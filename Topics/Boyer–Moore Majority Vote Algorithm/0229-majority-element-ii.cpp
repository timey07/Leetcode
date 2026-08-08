class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int curr1=0;
        int curr2=0;
        int count1=0;
        int count2=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==curr1) count1++;
            else if(nums[i]==curr2) count2++;
           else if(count1==0){
                curr1=nums[i];
                count1++;
            }else if(count2==0){
                curr2=nums[i];
                count2++;
            } else{
                count1--;
                count2--;
            }
        }

        count1=count2=0;
        for(int i=0;i<n;++i){
            if(nums[i]==curr1) count1++;
            else if(nums[i]==curr2) count2++;
        }
        vector<int> ans;
        if(count1>n/3) ans.push_back(curr1);
        if(count2>n/3) ans.push_back(curr2);
        return ans;
    }
};
