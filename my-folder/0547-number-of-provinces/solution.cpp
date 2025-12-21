class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n= isConnected.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;++i){
            if(vis[i]) continue;
            vis[i]=1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int a=q.front();
                q.pop();
                for(int j=0;j<n;++j){
                    if(j==a || vis[j]) continue;
                    if(isConnected[a][j]){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
