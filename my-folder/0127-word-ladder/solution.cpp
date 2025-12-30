class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(s.find(endWord)==s.end()) return 0;
        while(!q.empty()){
            int steps=q.front().second;
            string word=q.front().first;
            q.pop();
            for(int i=0;i<word.size();++i){
                char og=word[i];
            for(char c='a';c<='z';++c){
                word[i]=c;
                if(s.find(word)!=s.end()){
                    s.erase(word);
                    if(word==endWord) return steps+1;
                    q.push({word,steps+1}); 
                }
                word[i]=og;
            }
            }
        }
        return 0;
    }
};
