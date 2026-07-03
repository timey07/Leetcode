class Solution {
public:
    int count = 0;

    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        int left = l;
        int right = m + 1;

        
        int j = m + 1;
        for (int i = l; i <= m; ++i) {
            while (j <= r && arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += j - (m + 1);
        }

     
        left = l;
        right = m + 1;
        while (left <= m && right <= r) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= m) {
            temp.push_back(arr[left++]);
        }
        while (right <= r) {
            temp.push_back(arr[right++]);
        }
        for (int i = l; i <= r; ++i) {
            arr[i] = temp[i - l];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};

