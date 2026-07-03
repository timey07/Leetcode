class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[n-1].size();
        int ans=0;
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        priority_queue<
            pair<int,pair<int,int>>, 
            vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        while(!pq.empty()){
            int val=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(val>dis[x][y]) continue;
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int temp= max(val,abs(heights[x][y]-heights[nx][ny]));
                    if(temp<dis[nx][ny]){
                        dis[nx][ny]=temp;
                        pq.push({temp,{nx,ny}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};
