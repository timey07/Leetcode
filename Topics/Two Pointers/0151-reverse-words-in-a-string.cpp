#include <bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i=s.size()-1;
        while(i>=0){
            string temp;
            while(i>=0 && s[i]!=' '){
                temp+=s[i];
                i--;
            }
            if(!temp.empty()){
                if(!ans.empty()) ans+=' ';
                reverse(temp.begin(),temp.end());
                ans+=temp;
            }
            i--;
        }
        return ans;
    }
};
