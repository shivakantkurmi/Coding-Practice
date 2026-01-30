class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        vector<int> arr;
        while(!q.empty()){
            arr.push_back(q.front());
            q.pop();
        }
        int i=0,j=arr.size()/2;
        while(j<arr.size()){
            q.push(arr[i]);
            q.push(arr[j]);
            i++,j++;
        }
        
    }
};
