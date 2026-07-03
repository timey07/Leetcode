class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            
            int temp=nums[i];
            int rev=0;
            if(mp[temp]) ans=min(ans,i+1-mp[temp]);
            while(temp){
                int rem=temp%10;
                rev*=10;
                rev+=rem;
                temp/=10;
            }
            cout << rev << " ";
            mp[rev]=i+1;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
