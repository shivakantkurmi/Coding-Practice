//link : https://www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    unordered_map<string,int> mp;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            string name;
            int marks;
            cin >> name >> marks;
            mp[name] += marks;
        }
        else if(type == 2){
            string name;
            cin >> name;
            mp.erase(name);
        }
        else if(type == 3){
            string name;
            cin >> name;
            cout << mp[name] << '\n';
        }
    }

    return 0;
}

