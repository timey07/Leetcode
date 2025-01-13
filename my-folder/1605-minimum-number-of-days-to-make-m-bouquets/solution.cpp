class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
          if(  n < (long long ) k * m  )
        {
          return -1;
        }
        int  low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;++i){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=0;
            int temp=0;
            for(int i=0;i<n;++i){
                if(mid>=bloomDay[i]) temp++;
                else temp=0;
                if(temp==k){
                    sum++;
                    temp=0;
                }
            }
            if(sum>=m){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
