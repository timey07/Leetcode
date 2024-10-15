class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int j=0;
        int maxi=0;
        for(int i=1;i<intervals.size();++i){
            maxi=max(maxi,intervals[i-1][1]);
            if(maxi<intervals[i][0]){
                vector<int>temp={intervals[j][0],maxi};
                ans.push_back(temp);
                j=i;
                maxi=0;
            }
           
        } maxi=max(maxi,intervals[intervals.size()-1][1]);
vector<int>temp={intervals[j][0],maxi};
                ans.push_back(temp);
        return ans;
    }
};
