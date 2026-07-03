class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> mp(26,0);
        for(int i=0;i<s.size();++i){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        for(auto i:mp){
            if(i!=0) return false;
        }
        return true;
    }
};
