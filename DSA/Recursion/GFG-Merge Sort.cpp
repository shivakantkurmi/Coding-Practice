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
