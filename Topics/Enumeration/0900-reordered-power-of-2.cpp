class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<31;++i){
            int temp= 1 << i;
            string c=to_string(temp);
            if(c.size()!=s.size()) continue;
            sort(c.begin(),c.end());
            if(s==c) return true;
        }
        return false;
    }
};
