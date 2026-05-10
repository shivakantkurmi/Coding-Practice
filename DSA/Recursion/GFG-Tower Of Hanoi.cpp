class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        if(n==0) return 0;
        return 2*(towerOfHanoi(n-1,from,to,aux))+1;
        
    }
};


class Solution {
  public:
    int count=0;
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n==0) return 0;
        towerOfHanoi(n-1,from,aux,to);
        count++;
        towerOfHanoi(n-1,aux,to,from);
        return count;
    }
};
