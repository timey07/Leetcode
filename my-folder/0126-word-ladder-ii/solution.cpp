class Solution {
    int sz;
    private:
    void dfs(string start,string word,vector<string>& seq,vector<vector<string>>& ans,unordered_map<string,int>& mp){
        if(word==start){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mp[word];
        for(int i=0;i<sz;++i){
            char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(mp.find(word)!=mp.end() && mp[word]==steps-1){
                        seq.push_back(word);
                        dfs(start,word,seq,ans,mp);
                        seq.pop_back();
                    }
                    word[i]=og;
                }
            }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string,int> mp;
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        if(st.find(endWord)==st.end()) return ans;
        st.erase(beginWord);
        q.push({beginWord});
        mp[beginWord]=1;
        sz=beginWord.size();

        while(!q.empty()){
            string word=q.front();
            int steps=mp[word];
            q.pop();
            if(word==endWord) break;
            string og=word;
            for(int i=0;i<sz;++i){
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word});
                        mp[word]=steps+1;
                    }
                    word=og;
                }
            }
        }
        if(mp[endWord]==0) return ans; 
        vector<string> seq;
        seq.push_back(endWord);
        dfs(beginWord,endWord,seq,ans,mp);
        return ans;
    }
};
