class Solution {
    public:
    vector<vector<string>> ans;
    string b;
    private:
    void dfs(unordered_map<string,int>&mpp,vector<string>&seq,string word){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
        }
        int steps=mpp[word];
        for(int i=0;i<word.size();++i){
                    char og=word[i];
                    
                    for(char c='a';c<='z';++c){
                        word[i]=c;
                        if(mpp[word]+1==steps){
                            seq.push_back(word);
                            dfs(mpp,seq,word);
                            seq.pop_back();
                        }     
                    }
                    word[i]=og;
                }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        unordered_map<string,int> mpp;
        mpp[beginWord]=1;
        
        q.push(beginWord);
        st.erase(beginWord);

        while(!q.empty()){

                string word=q.front();
                int steps=mpp[word];
                q.pop();
                
                if(word==endWord) break;
                
                for(int i=0;i<word.size();++i){
                    char og=word[i];
                    for(char c='a';c<='z';++c){
                        word[i]=c;
                        if(st.count(word)){
                            q.push(word);
                            mpp[word]=steps+1;
                            st.erase(word);
                        }     
                    }
                    word[i]=og;
                }
        }
        if(!st.count(endWord)){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(mpp,seq,endWord);
        }
        return ans;
    }
};
