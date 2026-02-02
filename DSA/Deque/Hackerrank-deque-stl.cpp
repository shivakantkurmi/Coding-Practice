//link : https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true

//1.using atoring indexs

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int &i:arr) cin >> i;

        deque<int> dq; // stores indices

        for(int i=0;i<n;i++){
            if(i>=k && dq.front()==i-k)dq.pop_front();
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            dq.push_back(i);

            // Print max
            if(i >= k-1)
                cout << arr[dq.front()] << " ";
        }
        cout << '\n';
    }

    return 0;
}


// 2. using value

// #include <bits/stdc++.h>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */

//     int t;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin>>n>>k;
//         vector<int>arr(n,0);
//         for(int &i:arr)cin>>i;
//         deque<int>dq;
//         for(int i=0;i<n;i++){
//             while(!dq.empty() && dq.back()<arr[i])dq.pop_back();
//             dq.push_back(arr[i]);
//             if(i>=(k-1)){
//                 cout<<dq.front()<<" ";
//                 if(dq.front()==arr[i-k+1])dq.pop_front();
//             }
//         }
//         cout<<"\n";
//     }
//     return 0;
// }

