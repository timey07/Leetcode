class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else{
                if(st.empty()){
                    st.push(it);
                    break;
                }
                if(st.top()=='(' && it==')') st.pop();
                else if(st.top()=='{' && it=='}') st.pop();
                else if(st.top()=='[' && it==']') st.pop();
                else break;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
