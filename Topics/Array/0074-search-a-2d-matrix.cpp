class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n-1;
        int row=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][0]==target) return true;
            if(matrix[mid][0]>target) high=mid-1;
            else if(matrix[mid][m-1]>=target){
                row=mid;
                break;
            }
            else low=mid+1;
        }
        if(row==-1) return false;
        low=0;
        high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};
