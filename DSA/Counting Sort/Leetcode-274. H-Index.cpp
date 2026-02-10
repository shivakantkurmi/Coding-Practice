/*
Intuition
The H-index is the maximum value h such that there are at least h papers with ≥ h citations.
Instead of sorting (O(n log n)), we can use a counting approach:
Count how many papers have each citation count.
Then accumulate from higher citations to lower.
As soon as total papers ≥ current citation value, we found our H-index.

Also note:
👉 H-index can never exceed n (number of papers).
So any citation > n is treated as n.

Approach
Create a frequency array count of size n+1.
For each citation:
If citation ≥ n → put in count[n]
Else → increment count[citation]
Traverse from n down to 0:
Keep adding counts cumulatively.
When total papers ≥ current index → return it.

Complexity
Time complexity: 𝑂(𝑛)
Space complexity:𝑂(𝑛)
(Count array)
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxi=*max_element(citations.begin(),citations.end());
        vector<int> count(maxi+1,0);
        for(int i:citations) count[i]++;
        for(int i=maxi;i>0;i--){
            count[i-1]+=count[i];
            if(count[i]>=i)return i;
        }
        return citations[0];

    }
};
