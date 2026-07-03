class Solution {
      public:
     void solve(int num, string temp, vector<string> &ans, int check){
         if(num==0){
           ans.push_back(temp);  
           return;
         }
         solve(num-1,temp+'1',ans,1);
         if(check) solve(num-1,temp+'0',ans,0);
     }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(n,"",ans,1);
        return ans;
    }
};
