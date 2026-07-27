class Solution {
    private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int n=s.size();
        int sum=0;
        int low=0;
        for(int i=0;i<n;++i){
            if(isVowel(s[i])) sum++;
            if(i-low+1==k){
                ans=max(ans,sum);
                if(isVowel(s[low])) sum--;
                low++;
            }
        }
        return ans;
    }
};
