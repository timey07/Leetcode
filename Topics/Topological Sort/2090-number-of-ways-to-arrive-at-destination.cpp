class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> q;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        q.push({0,0});
        vector<vector<pair<int,int>>> list(n);
        for(int i=0;i<roads.size();++i){
            int a=roads[i][0];
            int b=roads[i][1];
            int val=roads[i][2];
            list[a].push_back({b,val});
            list[b].push_back({a,val});
        }
        int ans=0;
        while(!q.empty()){
            long long val=q.top().first;
            int node=q.top().second;
            q.pop();
            if(val>dist[node]) continue;
            for(auto it:list[node]){
                long long nval=val+it.second;
                if(dist[it.first]>nval){
                    dist[it.first]=nval;
                    q.push({nval,it.first});
                    ways[it.first]=ways[node];
                }
        else if(dist[it.first]==nval) ways[it.first]=(ways[it.first]+ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};
