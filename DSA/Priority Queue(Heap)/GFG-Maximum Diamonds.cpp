class Solution {
  public:
    long long maxDiamonds(vector<int>& arr, int k) {
        // code here
        priority_queue<int> pq;//default max heap
        long long ans=0;
        for(int i:arr)pq.push(i);
        while(k && pq.top()>0){
            k--;
            int x=pq.top();
            ans+=x;
            pq.pop();
            pq.push(x/2);
        }
        return ans;
    }
};
