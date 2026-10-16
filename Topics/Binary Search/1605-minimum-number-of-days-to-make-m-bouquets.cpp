class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k > n) return -1;
        int low=INT_MAX; 
        int high=INT_MIN; 
        for(int i=0;i<n;++i){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int count=0;
            int sum=0;
            for(int i=0;i<n;++i){
                if(bloomDay[i]<=mid) count++;
                else count=0;
                if(count==k){
                    sum++;
                    count=0;
                }
                if(sum==m) break;
            }
            if(sum==m){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
