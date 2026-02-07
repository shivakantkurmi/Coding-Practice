// class Solution {
//   public:

//     // Function to return length of longest subsequence of consecutive integers.
//     int longestConsecutive(vector<int>& arr) {
//         // Your code here
//         unordered_map<int,int> mp;
//         int ans=0;
//         for(int i : arr)mp[i]=1;
//         for(auto i :arr){
//             int t=0;
//             int x=i,y=i;
//             while(mp.find(x)!=mp.end()){
//                 t+=mp[x];
//                 mp.erase(x);
//                 x++;
//             }
//             mp[y]=t;
//             ans=max(t,ans);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());

        int ans = 0;

        for(int num : st){
            // start of sequence
            if(st.find(num-1) == st.end()){
                int curr = num;
                int len = 1;

                while(st.find(curr+1) != st.end()){
                    curr++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};
