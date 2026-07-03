class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> ee(26,0),oo(26,0);
        for(int i=0;i<s2.size();++i){
            if(i%2) oo[s2[i]-'a']++;
            else ee[s2[i]-'a']++;
        }
        for(int i=0;i<s1.size();++i){
            if(i%2 && oo[s1[i]-'a']) oo[s1[i]-'a']--;
            else if(i%2==0 && ee[s1[i]-'a']) ee[s1[i]-'a']--;
            else return false; 
        }
        return true;
    }
};
