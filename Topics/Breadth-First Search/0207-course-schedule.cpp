class Solution {  
    private:
    bool dfs(int node,vector<int> list[],vector<int>&vis,vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:list[node]){
            if(!vis[it]){
                if(dfs(it,list,vis,pathVis)==false) return false; 
                }
                else if(pathVis[it]) return false;
        }

        pathVis[node]=0;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          int n=prerequisites.size();
        vector<int> list[numCourses];
        for(int i=0;i<n;++i){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            list[b].push_back(a);
        }
        
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;++i){
            if(vis[i]) continue;
            if(dfs(i,list,vis,pathVis)==false) return false;
        }
        return true;
    }
};
