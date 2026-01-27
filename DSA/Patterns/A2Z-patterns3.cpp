/*
Pattern 1:
1 
2 3
4 5 6
7 8 9 10
11 12 13 14 15


Pattern 2:

A
AB
ABC
ABCD
ABCDE


Pattern 3:

ABCDE
ABCD
ABC
AB
A


pattern 4:

A
BB
CCC
DDDD
EEEEE


pattern 5:
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

*/

#include<iostream>
using namespace std;

void pattern1(int n){
    int x=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<x++<<" ";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        char x='A';
        for(int j=0;j<=i;j++){
            cout<<x++;
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=n;i>0;i--){
        char x='A';
        for(int j=0;j<i;j++){
            cout<<x++;
        }
        cout<<endl;
    }
}

void pattern4(int n){
    char x='A';
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<x;
        }
        x++;
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=1;i<=n;i++){
        char c='A';
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<c++;
        }
        --c;
        for(int j=i-1;j>=1;j--){
            cout<<--c;
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
