class Solution {
    private:
    vector<int> primes;
    map<int,int> mp;
    void sieve(int n = 100005) {
    vector<bool> isComposite(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (!isComposite[i]) {
            primes.push_back(i);
            mp[i]++;
            for (int j = i + i; j <= n; j += i) {
                isComposite[j] = 1;
            }
        }
    }
}
public:
    int minOperations(vector<int>& nums) {
        sieve();
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            if(i%2==0){
                if(mp[nums[i]]) continue;
                int in=upper_bound(primes.begin(),primes.end(),nums[i])-primes.begin();
                ans+=primes[in]-nums[i];
                nums[i]=primes[in];
            }
            else{
                while(mp[nums[i]]){
                    nums[i]++;
                    ans++;
                }
            }
        }
        return ans;
    }
};
