class Solution {
    private:
    void rec(int sum,vector<int>&store,int n,vector<int> &v,int size,int index){
        if(size==4 && sum>11) return;
        if(size==6 && sum>59) return;
        if(n==0){
            store.push_back(sum);
            return;
        }
        if(index==size) return;
        rec(sum+v[index],store,n-1,v,size,index+1);
        rec(sum,store,n,v,size,index+1);
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> hour={8,4,2,1};
        vector<int> minute={32,16,8,4,2,1};
        vector<string> ans;
        for(int i=0;i<=turnedOn;++i){
            vector<int> h,m;
            rec(0,h,i,hour,4,0);
            rec(0,m,turnedOn-i,minute,6,0);
            string s;
            for(int j=0;j<h.size();j++){
                for(int k=0;k<m.size();++k){
                    
                if(m[k]>9) s=to_string(h[j])+":"+to_string(m[k]);
                    else s=to_string(h[j])+":0"+to_string(m[k]);
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
