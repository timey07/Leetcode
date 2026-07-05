class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int curr=it+1;
                int count=1;
                while(s.find(curr)!=s.end()){
                    count++;
                    curr++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
