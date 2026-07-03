class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<pair<int,int>> q;
        vector<int> dis(n+1,INT_MAX);
        q.push({k,0});
        dis[k]=0;
        vector<vector<pair<int,int>>> list(n+1);
        for(int i=0;i<times.size();++i){
            int a=times[i][0];
            int b=times[i][1];
            int val=times[i][2];
            list[a].push_back({b,val});
        }
        while(!q.empty()){
            int node=q.front().first;
            int val=q.front().second;
            q.pop();
            for(auto it:list[node]){
                int nval=val+it.second;
                if(dis[it.first]>nval){
                    dis[it.first]=nval;
                    q.push({it.first,nval});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;++i){
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};
