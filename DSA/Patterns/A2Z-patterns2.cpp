/*
Pattern 1: 
12345
1234
123
12
1

Pattern 2:
    *
   ***
  *****
 *******
*********

Pattern 3:
*********
 *******
  *****
   ***
    *
Pattern 4:
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

Pattern 5:
1        1
12      21
123    321
1234  4321
1234554321


*/

#include<iostream>
using namespace std;

void pattern1(int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}

void pattern2(int n){
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++){
        cout<<" ";
    }
    for(int j=1;j<=2*i-1;j++){
        cout<<"*";
    }
    cout<<endl;
   }
}

void pattern3(int n){
   for(int i=n;i>0;i--){
    for(int j=1;j<=n-i;j++){
        cout<<" ";
    }
    for(int j=1;j<=2*i-1;j++){
        cout<<"*";
    }
    cout<<endl;
   }
}

void pattern4(int n){
    bool b;
    for(int i=0;i<n;i++){
        b=(i%2==0);
        for(int j=0;j<=i;j++){
            cout<<b<<" ";
            b=!b;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        for(int j=i;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }
}

int main(){
    pattern1(5);
    pattern2(5);
    pattern3(5);
    pattern4(5);
    pattern5(5);
}
