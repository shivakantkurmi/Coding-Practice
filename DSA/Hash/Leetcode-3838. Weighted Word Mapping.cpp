class Solution {
    int weight(string &s, vector<int> &w){
        int sum=0;
        for(char c:s){
            sum+=w[c-'a'];
        }
        return sum%26;
    }
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string s:words){
            char c='z'-weight(s,weights);
            ans.push_back(c);
        }
        return ans;
    }
};
