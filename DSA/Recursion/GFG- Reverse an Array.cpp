class Solution {
  public:
  
    void swap(int &a, int &b){
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void recursiveReverse(vector<int> &arr, int i, int j){
        if(j<=i)return;
        swap(arr[i],arr[j]);
        recursiveReverse(arr,i+1,j-1);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        // int i=0,j=arr.size()-1;
        // while(i<j){
        //     swap(arr[i],arr[j]);
        //     i++,j--;
        // }
        
        recursiveReverse(arr,0,arr.size()-1);
        
        
    }
};
