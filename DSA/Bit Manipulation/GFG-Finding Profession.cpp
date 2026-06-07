class Solution {
  public:
    string profession(int level, int pos) {
        long long x = pos - 1;
        
        if (__builtin_popcountll(x) & 1)//is position-1 contains odd set bits then doctor
            return "Doctor";
        
        return "Engineer"; //else engineer
    }
};
