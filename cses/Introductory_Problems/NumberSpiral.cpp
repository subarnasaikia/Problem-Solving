#include<iostream>
using namespace std;

#define ll long long

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll y, x, ans;
        cin >> y>> x;
        ll maxi = max(y,x), mini = min(y, x);
        ans = (maxi&1 ? (maxi-1)*(maxi-1) + 1 : maxi*maxi);
        if(y < x)
        {
            ans = (maxi&1 ? (ans + (2*maxi - (mini + 1))) : (ans - (2*maxi - (mini + 1))));
        }else {
            ans = (maxi&1 ? (ans + ((mini - 1))) : (ans - ((mini - 1))));
        }
        cout << ans << endl;
    }
}