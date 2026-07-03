class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=commands.size();
        int m=obstacles.size();
        int x=0;
        int y=0;
        int ans=0;
        vector<char> dir={'N','E','S','W'};
        int in=0;
        for(int i=0;i<n;++i){
            if(commands[i]==-2){
                in--;
                if(in==-1) in=3;
                continue;
            }
            if(commands[i]==-1){
                in=(in+1)%4;
                continue;
            }
            int check=0;
            for(int j=0;j<m;++j){
            if(dir[in]=='N') {
        if(y+commands[i]>=obstacles[j][1] && y<obstacles[j][1] &&obstacles[j][0]==x){
            if(check) y= min(y,obstacles[j][1]-1);
            else y= obstacles[j][1]-1;
            check=1;
        }
            }
            else if(dir[in]=='S'){
        if(y-commands[i]<=obstacles[j][1] && y>obstacles[j][1] &&obstacles[j][0]==x){
            if (check) y= max(y,obstacles[j][1]+1);
            else y= obstacles[j][1]+1;
            check=1;
        }
            }
            else if(dir[in]=='E'){
        if(x+commands[i]>=obstacles[j][0] && x<obstacles[j][0] &&obstacles[j][1]==y){
            if(check) x= min(x,obstacles[j][0]-1);
            else x= obstacles[j][0]-1;
            check=1;
        }
            }
            else if(dir[in]=='W'){
        if(x-commands[i]<=obstacles[j][0] && x>obstacles[j][0] &&obstacles[j][1]==y){
            if(check) x= max(x,obstacles[j][0]+1);
            else x= obstacles[j][0]+1;
            check=1;
        }
            }
            }
            if(!check){
                if(dir[in]=='N') y+=commands[i];
                else if(dir[in]=='S') y-=commands[i];
                else if(dir[in]=='W') x-=commands[i];
                else x+=commands[i];
            }
            int sum=x*x + y*y;
            ans=max(ans,sum);
        }
        return ans;
    }
};
