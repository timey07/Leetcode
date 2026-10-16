class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==endWord) return count;
            for(int i=0;i<word.size();++i){
                char og=word[i];
                for(char c='a';c<='z';++c){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push({word,count+1});
                        st.erase(word);
                    }
                    word[i]=og;
                }
            }
        }
        return 0;
    }
};
