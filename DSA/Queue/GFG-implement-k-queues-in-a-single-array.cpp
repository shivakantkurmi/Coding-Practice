//Link : https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/1

class kQueues {
    
  public:
    vector<queue<int>> kq;
    int ele;
    int total;
    kQueues(int n, int k) {
        // Initialize your data members
        kq.resize(k);
        ele=0;
        total=n;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        kq[i].push(x);
        ele++;
    }

    int dequeue(int i) {
        // dequeue element from queue i
       if(kq[i].empty()) return -1;
       else {
           int x=kq[i].front();
           ele--;
           kq[i].pop();
           return x;
       }
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return kq[i].empty();
    }

    bool isFull() {
        // check if array is full
        return ele==total;
    }
};
