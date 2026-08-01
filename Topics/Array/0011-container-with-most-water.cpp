class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int ans=0;
        while(low<high){
            int cap= min(height[low],height[high])*(high-low);
            ans=max(ans,cap);
            if(height[low]<=height[high]) low++;
            else high--;
        }
        return ans;
    }
};
