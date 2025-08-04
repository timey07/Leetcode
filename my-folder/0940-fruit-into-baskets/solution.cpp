class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0;
        int right=0;
        int ans=0;
        map<int,int> mp;
        while(right<fruits.size()){
            mp[fruits[right]]++;
            while(mp.size()>2){
                    mp[fruits[left]]--;
               if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                                   left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
