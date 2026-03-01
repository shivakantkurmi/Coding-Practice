class Solution {
public:
    int minPartitions(string n) {
        int max_digit=0;
        for(char ch:n){
            int curr_digit=ch-'0';
            max_digit=max(max_digit,curr_digit);
        }
        return max_digit;
        
    }
};
