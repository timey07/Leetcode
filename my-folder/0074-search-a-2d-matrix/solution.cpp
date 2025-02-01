class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int high=matrix.size()-1;
        while(low<=high){
            int mid=(low+high) >> 1;
            if(matrix[mid][0]==target) return true;
            if(matrix[mid][0]>target) high=mid-1;
            else{
                int less=0;
                int more=matrix[mid].size()-1;
                while(less<=more){
                    int bw=(less+more)/2;
                    if(matrix[mid][bw]==target) return true;
                    if(matrix[mid][bw]>target) more=bw-1;
                    else less=bw+1;
                }
                low=mid+1;
            }
        }
        return false;
    }
};
