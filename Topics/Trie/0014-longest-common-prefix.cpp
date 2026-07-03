class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int check=0;
        for(int j=0;j<strs[0].size();++j){
            for(int i=0;i<strs.size()-1;++i){
                if(strs[i].size()<j){
                    check=1;
                    break;
                }
                if(strs[i][j]!=strs[i+1][j]){
                    check=1;
                    break;
                }
            }
                if(check) break;
                ans+=strs[0][j];
            }
            return ans;
        }
    };
