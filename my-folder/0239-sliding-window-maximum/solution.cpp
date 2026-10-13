class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(i>=k && nums[i-k]==dq.front()) dq.pop_front();
            while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
            if(i+1>=k) ans.push_back(dq.front());
        }
        return ans;
    }
};
