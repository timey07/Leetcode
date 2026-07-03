class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int in=0;
        int i=0;
        int j=0;
        while(i<s.size()){
            if(s[i]==goal[in%goal.size()])i++;
           else{ i=0;in=j;j++;}
            in++;
            if(in>2*s.size()+1) return false;
        }
        return true;
    }
};
