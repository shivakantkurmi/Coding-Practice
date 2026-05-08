class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];

        int i = low - 1;
        int j = high + 1;

        while(true) {

            do {
                i++;
            } while(arr[i] < pivot);

            do {
                j--;
            } while(arr[j] > pivot);

            if(i >= j)
                return j;

            swap(arr[i], arr[j]);
        }
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if(low >= high) return;

        int p = partition(arr, low, high);

        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
};
