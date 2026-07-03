class Solution {
public:
    long long convert(string &s, int index, long long result, int sign) {
        if (index >= s.size() || !isdigit(s[index])) 
            return result * sign;
        
        result = result * 10 + (s[index] - '0');
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
        
        return convert(s, index + 1, result, sign);
    }

    int myAtoi(string s, int index = 0, int sign = 1) {
        while (index < s.size() && s[index] == ' ') index++;
        if (index < s.size() && (s[index] == '-' || s[index] == '+')) 
            sign = (s[index++] == '-') ? -1 : 1;
        
        return convert(s, index, 0, sign);
    }
};


