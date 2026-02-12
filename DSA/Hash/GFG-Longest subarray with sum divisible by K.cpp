class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {

        unordered_map<int,int> mp;
        // mp[0] = -1; // base case
        int sum = 0;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            sum = (sum % k + k) % k;
            if(sum==0)ans=i+1; // we can use this instead of mp[0]=-1;
            if(mp.find(sum) != mp.end()){
                ans = max(ans, i - mp[sum]);
            }
            else{
                mp[sum] = i; 
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     int longestSubarrayDivK(vector<int>& arr, int k) {

//         vector<int> first(k, -2); 
//         // -2 = not seen
//         // -1 = remainder 0 base case
        
//         first[0] = -1;

//         long long sum = 0;
//         int ans = 0;

//         for(int i = 0; i < arr.size(); i++){

//             sum += arr[i];

//             int rem = (sum % k + k) % k;

//             if(first[rem] != -2){
//                 ans = max(ans, i - first[rem]);
//             }
//             else{
//                 first[rem] = i;
//             }
//         }

//         return ans;
//     }
// };

