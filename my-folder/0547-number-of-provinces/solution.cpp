class Solution {
public:
void dfs(int node,vector<vector<int>> &c,vector<int> &v,int n){
    if(v[node]==1) return;
    v[node]=1;
    for(int i=0;i<n;++i){
        if(c[node-1][i]==1){
            dfs(i+1,c,v,n);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        vector<int> v(n+1);
        for(int i=1;i<=n;++i){
            if(!v[i]){
                dfs(i,isConnected,v,n);
                ans++;
            }
        }
        return ans;
    }
};
