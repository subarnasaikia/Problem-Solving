#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long a , b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        int x = ((a - b) + (a + b)/3)/2;
        int y = (a+b)/3 - x;
        // cout << x << " " << y << endl;
        int aa = 2 * x + y, bb = x + 2*y;
        if( a == aa && bb == b && x >= 0 && y >= 0){
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
    return 0;
}