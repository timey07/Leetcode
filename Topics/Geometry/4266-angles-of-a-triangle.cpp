class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        if(sides[0]+sides[1]<=sides[2]) return {};
        if(sides[0]+sides[2]<=sides[1]) return {};
        if(sides[2]+sides[1]<=sides[0]) return {};
        vector<double> ans(3);
        double a=sides[0];
        double b=sides[1];
        double c=sides[2];
        ans[0]=acos((b*b + c*c - a*a) / (2*b*c))* 180 / M_PI;
        ans[1]=acos((a*a + c*c - b*b) / (2*a*c))* 180 / M_PI;
        ans[2]=acos((a*a + b*b - c*c) / (2*a*b))* 180 / M_PI;
        sort(ans.begin(),ans.end());
        return ans;
    }
};
