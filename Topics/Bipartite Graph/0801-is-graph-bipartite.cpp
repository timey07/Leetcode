class Solution {
    private:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,int val){
        vis[node]=val;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,-val)==false) return false;
            }
            if(vis[it]==vis[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;++i){
            if(!vis[i]){
            if(dfs(i,graph,vis,1)==false) return false;
            }
        }
        return true;
    }
};
