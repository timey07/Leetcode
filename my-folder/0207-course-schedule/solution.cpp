class Solution {
    private:
    bool dfs(int node,vector<vector<int>>&list,vector<int>&vis,vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:list[node]){
            if(pathVis[it]) return false;
            if(!vis[it] && dfs(it,list,vis,pathVis)==false) return false;
        }
        pathVis[node]=0;
        return true;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(n);
        int sz=prerequisites.size();
        for(int i=0;i<sz;++i){
            list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=0;i<n;++i){
            if(vis[i]) continue;
            if(dfs(i,list,vis,pathVis)==false) return false;
        }
        return true;
    }
};
