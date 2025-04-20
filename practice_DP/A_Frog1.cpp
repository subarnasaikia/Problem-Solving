#include<bits/stdc++.h>
using namespace std;

using ll = int;
ll n ;
vector<ll> a;
ll dp[100000];

ll minCost(ll i)
{
    if(i >= n-1) return 0;
    if(dp[i] != -1) return dp[i];
    if(i+1 < n)
    {
        dp[i] = minCost(i+1) + abs(a[i] - a[i+1]);
    }
    if(i+2 < n)
    {
        dp[i] = min(dp[i], minCost(i+2) + abs(a[i] - a[i+2]) );
    }
    return dp[i];
}

int main()
{
    cin >> n;
    a.resize(n);
    memset(dp, -1, sizeof(dp));
    for(ll i = 0; i<n; i++) cin >> a[i];
    ll ans = minCost(0);
    cout << ans << endl;

    return 0;
}