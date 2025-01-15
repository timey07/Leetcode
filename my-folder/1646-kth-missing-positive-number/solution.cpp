class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        if(k<arr[0]) return k;
        if(k>=arr[n-1]-n+1) return (k+n);
        else{
            int low=0;
            int high=n-1;
            int ans=high;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]-mid<=k){
                    ans=mid+1;
                    low=mid+1;
                }
                else high=mid-1;
            }
            return k+ans;
        }
    }
};
