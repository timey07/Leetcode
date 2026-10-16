from pathlib import Path
from shutil import copy2
import requests

ROOT = Path("my-folder")
OUT = Path("Topics")

URL = "https://leetcode.com/graphql"

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
            timeout=20
        )
        r.raise_for_status()

        data = r.json() or {}
        question = (data.get("data") or {}).get("question") or {}
        tags = question.get("topicTags") or []

        return [x["name"] for x in tags if x and x.get("name")]

    except (requests.RequestException, ValueError) as e:
        print(f"Failed to fetch tags for {slug}: {e}")
        return []
OUT.mkdir(exist_ok=True)

for folder in ROOT.iterdir():
    if not folder.is_dir():
        continue

    slug = "-".join(folder.name.split("-")[1:])
    solution = folder / "solution.cpp"

    if not solution.exists():
        continue

    tags = get_tags(slug)

    for tag in tags:
        topic = OUT / tag
        topic.mkdir(exist_ok=True)

        copy2(solution, topic / f"{folder.name}.cpp")

print("Done")
