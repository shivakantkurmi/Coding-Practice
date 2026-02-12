
class Solution {
public:
    void relativeSort(vector<int>& a1, vector<int>& a2) {

        unordered_map<int,int> freq;

        // count frequencies of a1
        for(int x : a1)
            freq[x]++;

        vector<int> result;

        // place elements of a2 in order
        for(int x : a2){
            while(freq[x] > 0){
                result.push_back(x);
                freq[x]--;
            }
        }

        // collect remaining elements
        vector<int> leftover;

        for(auto &p : freq){
            while(p.second > 0){
                leftover.push_back(p.first);
                p.second--;
            }
        }

        // sort leftovers
        sort(leftover.begin(), leftover.end());

        // append leftovers
        for(int x : leftover)
            result.push_back(x);

        a1 = result;
    }
};
