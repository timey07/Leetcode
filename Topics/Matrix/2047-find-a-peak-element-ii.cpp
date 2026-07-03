class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=0;
        int col=0;
        int n=mat.size();
        int m=mat[0].size();
        while(true){
            if(row>=1){
                if(mat[row-1][col]>mat[row][col]){
                    row--;
                    continue;
                }
            }
            if(col>=1){
                if(mat[row][col-1]>mat[row][col]){
                    col--;
                    continue;
                }
            }
            if(row<n-1){
                if(mat[row+1][col]>mat[row][col]){
                    row++;
                    continue;
                }
            }
            if(col<m-1){
                if(mat[row][col+1]>mat[row][col]){
                    col++;
                    continue;
                }
            }
            return {row,col};
        }
        return {-1,-1};
    }
};
