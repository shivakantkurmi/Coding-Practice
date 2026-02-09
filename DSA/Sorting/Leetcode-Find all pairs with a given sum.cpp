class Solution {
public:
    vector<pair<int,int>> allPairs(int target,vector<int>& arr1, vector<int>& arr2) {

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        vector<pair<int,int>> res;

        int i = 0;
        int j = arr2.size() - 1;

        while(i < arr1.size() && j >= 0){
            int sum = arr1[i] + arr2[j];

            if(sum < target){
                i++;
            }
            else if(sum > target){
                j--;
            }
            else{
                int a = arr1[i];
                int b = arr2[j];

                int c1 = 0, c2 = 0;

                // count duplicates in arr1
                while(i < arr1.size() && arr1[i] == a){
                    c1++;
                    i++;
                }

                // count duplicates in arr2
                while(j >= 0 && arr2[j] == b){
                    c2++;
                    j--;
                }

                // add all combinations
                for(int x=0;x<c1*c2;x++){
                    res.push_back({a,b});
                }
            }
        }

        return res;
    }
};
