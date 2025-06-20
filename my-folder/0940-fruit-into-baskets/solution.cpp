class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        map<int,int> mp;
        int n=fruits.size();
        int ans=0;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()<=2) ans=max(ans,r-l+1);
            else{
                while(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};
