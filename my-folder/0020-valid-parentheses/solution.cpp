class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        int i=-1;
        int j=0;
        map<char,char> mp;
        mp['(']=')';
        mp['{']='}';
        mp['[']=']';
        while(j<n){
            if(s[j]=='(' || s[j]=='{' || s[j]=='['){
                i++;
                s[i]=s[j];
            }
            else if(i!=-1 && mp[s[i]]==s[j]) i--;
            else return false;
            j++;
        }
        if(i!=-1) return false;
        return true;
    }
};
