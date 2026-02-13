// User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr, int N) {
        // code here
        arr[N-1]++;
        if(arr[N-1]!=10)return arr;
        arr[N-1]=0;
        bool carry=1;
        for(int i=N-2;i>=0;i--){
            if(carry && arr[i]==9){
                arr[i]=0;
            }
            else if(carry)arr[i]++,carry=0;
            else return arr;
        }
        if(carry) arr.insert(arr.begin(),1);
        return arr;
    }
};
