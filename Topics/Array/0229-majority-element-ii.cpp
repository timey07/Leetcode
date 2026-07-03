class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int count1=0,count2=0;
        int ans1=INT_MIN,ans2=INT_MIN;
        ans1;
        int check=nums.size()/3;
        for(int i=0;i<nums.size();++i){
            if(count1==0 && nums[i]!=ans2){
                ans1=nums[i];
                count1++;
            }
            else if(count2==0 && nums[i]!=ans1){
                ans2=nums[i];
                count2++;
            }
            else if(ans1==nums[i]) count1++;
            else if(ans2==nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
          
        }
        count1=0,count2=0;
        for(int i=0;i<nums.size();++i){
            if(ans1==nums[i]) count1++;
            if(ans2==nums[i]) count2++;
        }
           if(count1>check){
                ans.push_back(ans1);
                // count1=0;
            }
            if(count2>check){
                ans.push_back(ans2);
                // count2=0;
            }
            
            return ans;
    }
};
