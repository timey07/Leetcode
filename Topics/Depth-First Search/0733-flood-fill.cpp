class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int c=image[sr][sc];
        if(c==color) return image;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();

            int dx[]={0,1,0,-1};
            int dy[]={1,0,-1,0};
            for(int i=0;i<4;++i){
                int x=a+dx[i];
                int y=b+dy[i];

                if(x>=0 && y>=0 && x<m && y<n && image[x][y]==c){
                    image[x][y]=color;
                    q.push({x,y});
                }
            }
        }
        return image;
    }
};
