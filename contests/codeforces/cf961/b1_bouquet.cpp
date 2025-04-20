#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        map<ll, ll> mp;
        for(int i=0; i<n; i++)
        {
            ll ele;
            cin >> ele;
            mp[ele]++;
        }
        ll ans = 0;
        for(auto& el : mp)
        {
            ll x= el.first;
            if(x > m) break;
            ll k1 =min(el.second, m/x);
            while(k1 > 0)
            {
                ll cur = k1 * x;
                ll nexX = x + 1;
                if(mp.find(x+1) == mp.end())
                {
                    ans = max(ans , cur);
                    break;
                }
                ll k2 =mp[x + 1];
                k2 = min(k2, (m -cur)/nexX);
                if(cur + (x + 1)*k2 <= m) ans = max(ans,(cur + (x + 1)*k2) );
                k1--;
            }
            
        }
        cout << ans << endl;
    }
    return 0;
}