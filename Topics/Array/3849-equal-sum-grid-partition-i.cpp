class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long total=0;
        vector<long long> rsum(n);
        vector<long long> csum(m);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                csum[j]+=grid[i][j];
                rsum[i]+=grid[i][j];
                total+=grid[i][j];
            }
        }
        long long sum1=0;
        long long sum2=0;
        for(int i=0;i<m;++i){
            sum1+=csum[i];
            if(sum1==(total-sum1)) return true;
        }
        for(int i=0;i<n;++i){
            sum2+=rsum[i];
            if(sum2==(total-sum2)) return true;
        }
        return false;
    }
};
