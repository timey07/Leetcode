class Solution {
public:
    string expand(string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            string a = expand(s, i, i);
            string b = expand(s, i, i + 1);
            ans = (a.size() > ans.size()) ? a : ans;
            ans = (b.size() > ans.size()) ? b : ans;
        }
        return ans;
    }
};

