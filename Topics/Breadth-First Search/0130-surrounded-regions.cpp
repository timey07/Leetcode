class Solution {
    private:
    bool dfs(int x,int y,vector<vector<char>>&board,vector<vector<int>>&vis,int n,int m){
        vis[x][y]=1;
        bool ans=false;
        ans|=(x==0 || y==0 || x==n-1 || y==m-1);
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        for(int i=0;i<4;++i){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx<n && ny<m && nx>=0 && ny>=0){
                if(board[nx][ny]=='O'){
                    if(!vis[nx][ny]) ans|=dfs(nx,ny,board,vis,n,m);
                }
            }
        }
        return ans;
    }
    private:
    void makeX(int x,int y,vector<vector<char>>&board,int n,int m){
        board[x][y]='X';
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int i=0;i<4;++i){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx<n && ny<m && nx>=0 && ny>=0){
                if(board[nx][ny]=='O'){
                   board[nx][ny]='X';
                   makeX(nx,ny,board,n,m);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i+=max(1,n-1)){
            for(int j=0;j<m;++j){
                if(board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i+=max(1,m-1)){
            for(int j=0;j<n;++j){
                if(board[j][i]=='O'){
                    q.push({j,i});
                    vis[j][i]=1;
                }
            }
        }

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            int dx[]={0,-1,0,1};
            int dy[]={1,0,-1,0};
            for(int i=0;i<4;++i){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && board[nx][ny]=='O'){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j]) board[i][j]='X';
            }
        }
    }
};
