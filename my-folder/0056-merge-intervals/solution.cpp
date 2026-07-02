class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        // ans.push_back({intervals[0][0],intervals[0][1]});
        ans.push_back(intervals[0]);
        int in=0;
        for(int i=1;i<n;++i){
            int a=intervals[i][0];
            int b=intervals[i][1];
            if(a<=ans[in][1] && b>=ans[in][0]){
                ans[in][0]=min(ans[in][0],a);
                ans[in][1]=max(ans[in][1],b);
            }
            else{
                ans.push_back({a,b});
                in++;
            }
        }
        return ans;
    }
};
