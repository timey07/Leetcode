class Solution {
    private:
    int find(int node,vector<int>&parent){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node],parent);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> sz(n,1);
        vector<int> parent(n);
        for(int i=0;i<n;++i) parent[i]=i;
        int eedges=0;
        int comp=0;
        for(int i=0;i<connections.size();++i){
            int a=connections[i][0];
            int b=connections[i][1];
            int upa=find(a,parent);
            int upb=find(b,parent);
            if(upa==upb){
                eedges++;
                continue;
            }
            if(sz[upa]==sz[upb]){
                parent[upb]=upa;
                sz[upa]+=sz[upb];
            }
            else if(sz[upa]>sz[upb]) parent[upb]=upa;
            else parent[upa]=upb;
        }
        for(int i=0;i<n;++i) if(parent[i]==i) comp++;
        if(eedges>=comp-1) return comp-1;
        else return -1;
    }
};
