class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=0;
            int d=1;
            for(int i=0;i<n;++i){
                if(sum+weights[i]>mid){
                    d++;
                    sum=0;
                }
                sum+=weights[i];
                if(d>days) break;
            }
            if(d<=days){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
