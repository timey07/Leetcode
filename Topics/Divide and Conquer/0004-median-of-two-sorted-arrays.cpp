class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
             if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int low=0;
        int high=n;
        while(low<=high){
            int p1=(low+high)/2;
            int p2=(n+m+1)/2 -p1;
            int left1=INT_MIN;
            int right1=INT_MAX;
            if(p1!=0) left1=nums1[p1-1];
            if(p1!=n) right1=nums1[p1];
            int left2=INT_MIN;
            int right2=INT_MAX;
            if(p2!=0) left2=nums2[p2-1];
            if(p2!=m) right2=nums2[p2];

            if(left1<=right2 && left2<=right1){
                if( (n+m)%2==0){
                    return (max(left1,left2) + min(right1,right2))/2.0;   
                }
                else {
                    return max(left1,left2);
                }
            }
            else if(left1>right2) high=p1-1;
            else low=p1+1;
        }
        return 0;
    }
};
