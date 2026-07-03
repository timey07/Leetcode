class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> array(nums.begin(),nums.end());
        vector<long long> ans;
        int n=array.size();
        stack<long long> s;
        s.push(0);
        for(int i=1;i<n;++i){
            int j=i;
            while(true){
                if(!s.empty() && array[s.top()]==array[j]){
                    array[j]=0;
                    j=s.top();
                    array[j]*=2;
                    s.pop();
                }
                else{
                    s.push(j);
                    break;
                }
            }
        }
        for(int i=0;i<n;++i){
            if(array[i]!=0) ans.push_back(array[i]);
        }
        return ans;
    }
};
