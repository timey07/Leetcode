class Solution {
int merge(vector<int>& arr,int low,int mid,int high){
  int l=low;
  int h=mid+1;
  vector<int> temp;
  int count=0;
  int j=mid+1;
  for(int i=low;i<=mid;i++){
    while(j<=high && arr[i]>2LL*arr[j]){
      j++;
    }
    count+= (j-(mid+1));
  }
  while(l<=mid && h<=high){
    if(arr[l]<=arr[h]){
      temp.push_back(arr[l]);
      l++;
    }
    else{
      temp.push_back(arr[h]);
      h++;
    }
  }
  while(l<=mid){
    temp.push_back(arr[l]);
      l++;
  }
  while(h<=high){
    temp.push_back(arr[h]);
      h++;
  }

  for(int i=low;i<=high;++i){
    arr[i]=temp[i-low];
  }
  return count;
}
int mergesort(vector<int>&arr,int low,int high){
  if(low>=high) return 0;
  int mid=(low+high)/2;
  int left=mergesort(arr,low,mid);
  int right=mergesort(arr,mid+1,high);
  return left + right + merge(arr,low,mid,high);
}
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
