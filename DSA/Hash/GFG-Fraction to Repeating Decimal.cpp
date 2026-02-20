class Solution {
  public:
    string calculateFraction(int a, int b) {
        
        string result = to_string(a / b);
        long long remainder = a % b;
        
        if (remainder == 0)
            return result;
        
        result += ".";
        
        unordered_map<long long, int> mp;
        
        while (remainder != 0) {
            
            // If remainder repeats → insert '('
            if (mp.find(remainder) != mp.end()) {
                result.insert(mp[remainder], "(");
                result += ")";
                break;
            }
            
            // Store position of this remainder
            mp[remainder] = result.size();
            
            remainder *= 10;
            result += to_string(remainder / b);
            remainder %= b;
        }
        
        return result;
    }
};
