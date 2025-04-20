#include <bits/stdc++.h>
using namespace std;

#define ll long long
int flag = 0, N=1;;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), c(n);
        for(auto& i : a) cin >> i;
        for(auto& i : c) cin >> i;
        unordered_map<ll, ll> hash;
        for(int i = 0; i<n; i++)
        {
            hash[a[i]] = c[i];
        }
        ll ans = 0;
        for(auto& eachPair : hash)
        {
            ll x = eachPair.first;
            if(x > m) continue;
            ll cur = m;
            ll k1 = min(eachPair.second, cur/x);
            ans = max(ans , k1*x);
            cur -= (k1*x);
            if(hash.find(x+1) == hash.end()) continue;
            ll k2 = min(hash[x+1], cur/(x+1));
            cur -= (k2*(x+1));
            ll k3 = min({k1, hash[x+1] - k2, cur});
            cur -= k3;
            ans = max(ans, m - cur);
        }
        cout << ans << endl;
    }
    return 0;
}