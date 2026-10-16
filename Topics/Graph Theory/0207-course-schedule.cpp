class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;++i){
            list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> inDegree(numCourses);
        for(int i=0;i<numCourses;++i){
            for(auto it:list[i]){
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(inDegree[i]==0) q.push(i);
        }
        int sz=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            sz++;
            for(auto it:list[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        if(sz==numCourses) return true;
        return false;
    }
};
