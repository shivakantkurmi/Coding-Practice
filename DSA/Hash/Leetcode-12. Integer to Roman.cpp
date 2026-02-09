class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> values = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"}
        };

        string result = "";

        for (auto &p : values) {
            while (num >= p.first) {
                result += p.second;
                num -= p.first;
            }
        }

        return result;
    }
};



// class Solution {
// public:
//     string intToRoman(int num) {
//         static string thousands[] = {"", "M", "MM", "MMM"};
//         static string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//         static string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//         static string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

//         return thousands[num/1000] +
//                hundreds[(num%1000)/100] +
//                tens[(num%100)/10] +
//                ones[num%10];
//     }
// };
