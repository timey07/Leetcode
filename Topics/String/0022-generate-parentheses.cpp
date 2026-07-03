class Solution {
    public:
    void solve(int i,int n,string temp,vector<string> &ans,int count,int count2){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        if(count<(n/2)){
            solve(i+1,n,temp+'(',ans,++count,++count2);
            count--;
            count2--;
        }
        if(count2>0){
            solve(i+1,n,temp+')',ans,count,--count2);
            count2++;
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,n*2,"",ans,0,0);
        return ans;
    }
};
