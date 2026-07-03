class Solution {
    public:
    vector<int> solve(string exp){

        vector<int> ans;
        int n=exp.size();
        for(int i=0;i<n;++i){
            if(!isdigit(exp[i])){
                vector<int> left=solve(exp.substr(0,i));
                vector<int> right=solve(exp.substr(i+1));

                for(auto a:left){
                    for(auto b:right){
                        if(exp[i]=='+') ans.push_back(a+b);
                        if(exp[i]=='-') ans.push_back(a-b);
                        if(exp[i]=='*') ans.push_back(a*b);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(exp));
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string exp) {
       return solve(exp);
    }
};
