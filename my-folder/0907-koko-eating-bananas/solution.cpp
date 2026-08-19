class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=0;
        for(int i=0;i<n;++i) maxi=max(piles[i],maxi);
        int ans=maxi;
        int low=1;
        int high=maxi;
        
        while(low<=high){
            int mid = (high-low)/2 +low;
            long long hours=0;
            for(int i=0;i<n;++i){
                hours+=((piles[i]+mid-1)/mid);
            }
            if(hours<=h){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
