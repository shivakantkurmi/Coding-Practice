// Link : https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int rMin=n+1,lMax=-1;
        for(int i:left){
            if(lMax<i)lMax=i;
        }
        for(int i:right){
            if(rMin>i)rMin=i;
        }
        return max(lMax,n-rMin);
    }
};
