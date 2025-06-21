class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        vector<int> mp(26,0);
        int maxi=0;
        int ans=0;
        while(r<s.size()){
            mp[s[r]-'A']++;
            maxi=max(maxi,mp[s[r]-'A']);
            while((r-l+1)-maxi>k){
                mp[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
