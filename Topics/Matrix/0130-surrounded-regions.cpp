class Solution{
private:
    bool dfs(vector<vector<char>>& board,int a,int b,int m,int n,vector<vector<int>>& vis){
        vis[a][b]=1;
        if(a==0 || b==0 || a==m-1 || b==n-1) return false;

        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};
        bool ans=true;

        for(int i=0;i<4;++i){
            int x=a+dx[i];
            int y=b+dy[i];
            if(x>=0 && y>=0 && x<m && y<n && board[x][y]=='O' && !vis[x][y]){
                ans&=dfs(board,x,y,m,n,vis);
            }
        }
        return ans;
    }

    void makeX(vector<vector<char>>& board,int a,int b,int m,int n,vector<vector<int>>& vis){
        board[a][b]='X';

        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};

        for(int i=0;i<4;++i){
            int x=a+dx[i];
            int y=b+dy[i];
            if(x>=0 && y>=0 && x<m && y<n && board[x][y]=='O' && vis[x][y]){
                makeX(board,x,y,m,n,vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O' && i!=0 && j!=0 && i!=m-1 && j!=n-1)
                    q.push({i,j});
            }
        }

        vector<vector<int>> vis(m,vector<int>(n,0));
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();

            if(board[a][b]=='O' && !vis[a][b]){
                if(dfs(board,a,b,m,n,vis)){
                    makeX(board,a,b,m,n,vis);
                }
            }
        }
    }
};

