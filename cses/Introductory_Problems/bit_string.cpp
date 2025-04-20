#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>> n;
    long long ans = 1ll;
    while(n > 30)
    {
        long long mul = (1ll << 30) % MOD;
        ans = (ans * mul) % MOD;
        n -= 30;
    }
    long long mul = (1ll << n) % MOD;
    ans = (ans * mul) % MOD;
    cout << ans << endl;

}