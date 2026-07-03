class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1,mp2;
        for(int i=0;i<s.size();++i){
            if(mp1[s[i]]==0){
                mp1[s[i]]=t[i];
            }
            if(mp2[t[i]]==0){
                mp2[t[i]]=s[i];
            }
                if(mp1[s[i]]!=t[i]) return false;
                if(mp2[t[i]]!=s[i]) return false;
        }
        return true;
    }
};
