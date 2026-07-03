class Solution {
public:
void solve(int k,int n,vector<int> &ds,vector<vector<int>> &ans,int start){
    if(k==0){
       if(n==0) ans.push_back(ds);
        return;
    }
    for(int i=start;i>=1;--i){
        if(n<i) continue;
        ds.push_back(i);
        solve(k-1,n-i,ds,ans,i-1);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(n>45) return ans;
        vector<int> ds;
        solve(k,n,ds,ans,9);
        return ans;
    }
};
