#include <climits>
using namespace std;

class Solution {
public:
    int stringToInt(string str) {
        long result = 0;
        bool isNegative = false;
        int startIndex = 0;

        if (str[0] == '-') {
            isNegative = true;
            startIndex = 1;
        } else if (str[0] == '+') {
            startIndex = 1;
        }

        for (int i = startIndex; i < str.length(); ++i) {
            result = result * 10 + (str[i] - '0');

            if (result > INT_MAX) {
                return isNegative ? INT_MIN : INT_MAX;
            }
        }

        return isNegative ? -result : result;
    }

    int myAtoi(string s) {
        string ans;
        bool started = false;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && !started && ans.empty()) {
                continue;
            }
            if (!started) {
                if (s[i] == '-' || s[i] == '+') {
                    ans += s[i];
                    started = true;
                } 
                else if (s[i] >= '0' && s[i] <= '9') {
                    ans += s[i];
                    started = true;
                }
                else break;
            } 
            else {
                if (s[i] == '-' || s[i] == '+') {
                    break;
                }
                if (s[i] >= '0' && s[i] <= '9') {
                    ans += s[i];
                } 
                else {
                    break; 
                }
            }
        }
        return stringToInt(ans);
    }
};


