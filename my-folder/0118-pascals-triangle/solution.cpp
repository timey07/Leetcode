class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows,vector<int>());
        for(int i=1;i<=numRows;++i){
            v[i-1].resize(i); 
           v[i-1][0] = v[i-1][i-1] = 1; 
            for(int j=1;j<=i-2;++j){
                  v[i-1][j]=(v[i-2][j-1]+v[i-2][j]);
            }
        }
        return v;
    }
};
