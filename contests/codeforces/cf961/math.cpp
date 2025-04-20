#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k1 = 10, k2 = 4;
    while(k1--)
    {
        cout << k1*(n) + k2*(n+1) << endl;
        k2++;
    }
    return 0;
}