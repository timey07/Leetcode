class Solution {
    private:
    void solve(int i,int j,vector<vector<int>>&triangle){
        if(i==triangle.size()) return;
        if(j==triangle[i].size()){
            j=0;
            i++;
         }
         if(i==triangle.size()) return;
         
         int lu=INT_MAX;
         int u=INT_MAX;
         if(j>0) lu=triangle[i-1][j-1];
         if(j<triangle[i].size()-1) u=triangle[i-1][j];
         triangle[i][j]+=min(lu,u);
         solve(i,j+1,triangle);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int ans=INT_MAX;
        solve(1,0,triangle);
        int n=triangle.size();
        for(int i=0;i<triangle[n-1].size();++i){
            ans=min(ans,triangle[n-1][i]);
        }
        return ans;
    }
};
