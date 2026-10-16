class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        stack<int> s;
        vector<int> vis(n,0);
        for(int k=0;k<n;++k){
            if(vis[k]) continue;
            s.push(k);
            vis[k]=1;
        while(!s.empty()){
            int a=s.top();
            s.pop();
            vis[a]=1;
            for(int j=0;j<n;++j){
                if(isConnected[a][j] && !vis[j]){
                    s.push(j);       
                }
            }
        }
        ans++;
        }
        return ans;
    }
};
