class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
    queue<pair<int,pair<int,int>>> pq;
        vector<vector<pair<int,int>>> list(n);
        for(int i=0;i<flights.size();++i){
            int a=flights[i][0];
            int b=flights[i][1];
            int val=flights[i][2];
            list[a].push_back({b,val});
        }
        pq.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(!pq.empty()){
            int size=pq.size();
        
                int val=pq.front().first;
                int node=pq.front().second.first;
                int stops=pq.front().second.second;
                pq.pop();
                if(stops>k) continue;
                for(auto it:list[node]){
                    int nval=val+it.second;
                    if(nval<dist[it.first] && stops<=k){
                        dist[it.first]=nval;
                        pq.push({nval,{it.first,stops+1}});
                    }
                }  
            
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
