/*

pattern 1:

E 
D E
C D E
B C D E
A B C D E


pattern 2:

**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********


pattern 3:

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *


pattern 4:

*****
*   *
*   *
*   *
*****


pattern 5:

5 5 5 5 5 5 5 5 5
5 4 4 4 4 4 4 4 5
5 4 3 3 3 3 3 4 5
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5
5 4 4 4 4 4 4 4 5
5 5 5 5 5 5 5 5 5

*/


#include <iostream>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = 'A' + (n - i - 1);
        for (int j = 0; j <= i; j++)
        {
            cout << c++ << " ";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++) cout << "*";
        for (int j = 1; j <= 2 * (i - 1); j++) cout << " ";
        for (int j = 1; j <= n - i + 1; j++) cout << "*";
        cout << endl;
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= n - i + 1; j++) cout << "*";
        for (int j = 1; j <= 2 * (i - 1); j++) cout << " ";
        for (int j = 1; j <= n - i + 1; j++) cout << "*";
        cout << endl;
    }
}

void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cout<<"*";
        for(int j=1;j<=2*(n-i);j++) cout<<" ";
        for(int j=1;j<=i;j++) cout<<"*";
        cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        for(int j=1;j<=i;j++) cout<<"*";
        for(int j=1;j<=2*(n-i);j++) cout<<" ";
        for(int j=1;j<=i;j++) cout<<"*";
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}


void pattern5(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;
            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }
        cout << endl;
    }
}

int main()
{
    pattern1(5);
    pattern2(5);
    pattern3(5);
    pattern4(5);
    pattern5(5);

    return 0;
}
