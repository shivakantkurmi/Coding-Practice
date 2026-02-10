class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);

        for(int x : arr1)
            count[x]++;

        vector<int> result;
        // Step 2: Place elements from arr2
        for(int x : arr2){
            while(count[x]--){
                result.push_back(x);
            }
        }

        // Step 3: Place remaining elements
        for(int i = 0; i <= 1000; i++){
            while(count[i] > 0){
                result.push_back(i);
                count[i]--;
            }
        }

        return result;
    }
};
