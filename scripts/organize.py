from pathlib import Path
from shutil import copy2
import requests

ROOT = Path("my-folder")
OUT = Path("Topics")

URL = "https://leetcode.com/graphql"

HEADERS = {
    "Content-Type": "application/json",
    "Referer": "https://leetcode.com/",
    "User-Agent": "Mozilla/5.0"
}

QUERY = """
query getQuestion($titleSlug: String!) {
    question(titleSlug: $titleSlug) {
        topicTags {
            name
        }
    }
}
"""


def get_tags(slug):
    try:
        r = requests.post(
            URL,
            json={
                "query": QUERY,
                "variables": {
                    "titleSlug": slug
                }
            },
            headers=HEADERS,
            timeout=20
        )
        r.raise_for_status()
        data = r.json()

    except (requests.RequestException, ValueError) as e:
        print(f"Request failed for {slug}: {e}")
        return []

    if not isinstance(data, dict):
        print(f"Invalid response for {slug}")
        return []

    if data.get("errors"):
        print(f"GraphQL error for {slug}: {data['errors']}")

    result = data.get("data")

    if not isinstance(result, dict):
        print(f"Missing data for {slug}")
        return []

    question = result.get("question")

    if not isinstance(question, dict):
        print(f"Question not found for {slug}")
        return []

    tags = question.get("topicTags")

    if not isinstance(tags, list):
        print(f"Invalid topic tags for {slug}")
        return []

    return [
        tag["name"]
        for tag in tags
        if isinstance(tag, dict)
        and isinstance(tag.get("name"), str)
        and tag["name"].strip()
    ]


def main():
    if not ROOT.is_dir():
        raise SystemExit(f"Source folder not found: {ROOT}")

    OUT.mkdir(parents=True, exist_ok=True)

    copied = 0
    skipped = []

    for folder in sorted(ROOT.iterdir()):
        if not folder.is_dir():
            continue

        parts = folder.name.split("-", 1)

        if len(parts) != 2 or not parts[1]:
            continue

        slug = parts[1]
        solution = folder / "solution.cpp"

        if not solution.is_file():
            continue

        tags = get_tags(slug)

        if not tags:
            skipped.append(folder.name)
            continue

        for tag in tags:
            topic = OUT / tag.strip()
            topic.mkdir(parents=True, exist_ok=True)

            destination = topic / f"{folder.name}.cpp"
            copy2(solution, destination)
            copied += 1

    print(f"Done. Copied {copied} solution files.")

    if skipped:
        print(f"Warning: Could not organize {len(skipped)} problems:")
        for problem in skipped:
            print(f"  - {problem}")


if __name__ == "__main__":
    main()
