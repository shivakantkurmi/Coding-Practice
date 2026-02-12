class Solution {
public:
    vector<string> winner(string arr[], int n) {

        unordered_map<string,int> mp;

        // count votes
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        string winnerName = "";
        int maxVotes = 0;

        // find winner
        for(auto &p : mp){

            string name = p.first;
            int votes = p.second;

            if(votes > maxVotes){
                maxVotes = votes;
                winnerName = name;
            }
            else if(votes == maxVotes && name < winnerName){
                winnerName = name;
            }
        }

        return {winnerName, to_string(maxVotes)};
    }
};
