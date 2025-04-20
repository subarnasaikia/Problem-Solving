#include<bits/stdc++.h>
using namespace std;

using ll = int;
ll n ;
vector<ll> a;

int main()
{
    cin >> n;
    a.resize(n);
    for(ll i = 0; i<n; i++) cin >> a[i];
    int prev0 = 0;
    int prev1 = abs(a[1] - a[0]); 
    int cur;
    for(int i = 2; i<n; i++)
    {
        cur = min(prev0 + abs(a[i] - a[i-2]), prev1 + abs(a[i] - a[i-1]));
        prev0 = prev1;
        prev1 = cur;
    }
    cout << cur << endl;

    return 0;
}