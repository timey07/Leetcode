class Solution {
public:
    void solve(string &digits,vector<string> &store,string &s, vector<string> &ans, int p){
        if(p==digits.size()){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<4;++i){
            if(i==store[digits[p]-'2'].size()) continue;
            s.push_back(store[digits[p]-'2'][i]);
            solve(digits,store,s,ans,p+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string &digits) {
        vector<string> ans;
        if(digits=="") return ans;
        string s;
        vector<string> store={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,store,s,ans,0);

        return ans;
    }
};
