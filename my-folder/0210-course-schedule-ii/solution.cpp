class Solution {
    private:
bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>&list,vector<int>&ans){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:list[node]){
        if(pathVis[it]) return false;
        if(!vis[it] && dfs(it,vis,pathVis,list,ans)==false) return false;
    }
    ans.push_back(node);
    pathVis[node]=0;
    return true;
}
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<vector<int>> list(n);
        for(int i=0;i<v.size();++i){
            list[v[i][0]].push_back(v[i][1]);
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(vis[i]) continue;
            if(dfs(i,vis,pathVis,list,ans)==false) return {};
        }
        return ans;
    }
};
