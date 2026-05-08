class Solution {
public:
    void merge(vector<int>& A, vector<int>& B, vector<int>& arr, int l) {
        int p = A.size(), q = B.size();
        int i = 0, j = 0, k = l;

        while(i < p && j < q) {
            if(A[i] < B[j]) arr[k++] = A[i++];
            else arr[k++] = B[j++];
        }

        while(i < p) arr[k++] = A[i++];
        while(j < q) arr[k++] = B[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return;

        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        vector<int> A(arr.begin() + l, arr.begin() + mid + 1);
        vector<int> B(arr.begin() + mid + 1, arr.begin() + r + 1);

        merge(A, B, arr, l);
    }
};



//slightly changed variant 
class Solution {
public:
    void merge_sort(vector<int>& nums, int left, int right){
        if (left < right) {
            int mid = left + (right - left) / 2;
            merge_sort(nums, left, mid);
            merge_sort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> L(n1);
        vector<int> R(n2);
        
        for (int i = 0; i < n1; i++)
            L[i] = nums[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = nums[mid + 1 + i];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            } else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
