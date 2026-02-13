class Solution {
public:
    string uncommonChars(string& s1, string& s2) {
        vector<int> freq(26, 0);

        // Mark chars from s1
        for(char ch : s1){
            freq[ch - 'a'] = 1;
        }

        // Process s2
        for(char ch : s2){
            int c = ch - 'a';
            if(freq[c] == 1) 
                freq[c] = 3; 
            else if(freq[c] == 0) 
                freq[c] = 2; 
        }
        string ans = "";
        for(int i = 0; i < 26; i++){
            if(freq[i] == 1 || freq[i] == 2){
                ans.push_back(i + 'a');
            }
        }

        return ans;
    }
};
