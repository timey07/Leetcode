class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            int freq[26] = {0}, maxf = 0, minf = n;
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;
                maxf = max(maxf, freq[s[j] - 'a']);
                minf = n;
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) minf = min(minf, freq[k]);
                }
                sum += (maxf - minf);
            }
        }
        return sum;
    }
};

