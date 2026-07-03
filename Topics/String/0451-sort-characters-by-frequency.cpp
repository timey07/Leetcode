class Solution {
public:
    string frequencySort(string s) {
        vector<int>v(75,0);
        for(int i=0;i<s.size();++i){
            v[s[i]-'0']++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<75;++i){
            if(v[i]==0) continue;
            pq.push({v[i],'0'+i});
        }
        string ans;
        while(!pq.empty()){
               pair<int,char> top=pq.top();
                 for (int i = 0;i<top.first;i++){
                ans+=top.second;
            }
            pq.pop();
        }
        return ans;
    }
};
