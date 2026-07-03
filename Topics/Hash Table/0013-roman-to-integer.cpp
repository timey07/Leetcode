class Solution {
public:
    int romanToInt(string s) {
    int values[26] = {};
    values['I' - 'A'] = 1;
    values['V' - 'A'] = 5;
    values['X' - 'A'] = 10;
    values['L' - 'A'] = 50;
    values['C' - 'A'] = 100;
    values['D' - 'A'] = 500;
    values['M' - 'A'] = 1000;

    int result = 0;
    int prevValue = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
        int currentValue = values[s[i] - 'A'];

        if (currentValue < prevValue) {
            result -= currentValue; 
        } else {
            result += currentValue; 
        }

        prevValue = currentValue;
    }

    return result;
}
};
