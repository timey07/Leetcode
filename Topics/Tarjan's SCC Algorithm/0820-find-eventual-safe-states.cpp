class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> list(n);
        vector<int> inDegree(n,0);
        for(int i=0;i<n;++i){
            for(auto it:graph[i]){
                list[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;++i){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:list[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
