class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=1e4;
            }
        }
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            int dx[]={0,-1,0,1};
            int dy[]={-1,0,1,0};
            for(int i=0;i<4;++i){
                int x=a+dx[i];
                int y=b+dy[i];
                if(x>=0 && y>=0 && x<m && y<n){
                    if(mat[x][y]>mat[a][b]+1){
                        mat[x][y]=mat[a][b]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        return mat;
    }
};
