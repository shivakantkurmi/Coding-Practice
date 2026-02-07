// Link : https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1

class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int>a;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                cout<<i<<" ";
                if(i!=(n/i)) a.push_back(n/i);
            }
        }
        for(int i=a.size()-1;i>=0;i--) cout<<a[i]<<" ";
    }
};
