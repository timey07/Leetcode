class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n+1);
        int ans=0;
        for(int i=1;i<=n;++i){
            if(vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int a=q.front();
                q.pop();
                for(int j=0;j<n;++j){
                    if(isConnected[a-1][j]==1 && vis[j+1]==0){
                        vis[j+1]=1;
                        q.push(j+1);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
