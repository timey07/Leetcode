class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        int n=word.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;++i){
            int temp;
            if(int(word[i])>=97) mp1[word[i]-'a']++;
            else mp2[word[i]-'A']++;
        }
        for(int i=0;i<26;++i){
            if(mp1[i] && mp2[i]) ans++;
        }
        return ans;
    }
};