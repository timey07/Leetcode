class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        if(s.size()>n) return false;
        int in=0;
        for(int i=0;i<n;++i){
            if(t[i]==s[in]) in++;
            if(in==s.size())break;
        }
        if(in==s.size()) return true;
        return false;
    }
};
