#include <bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 10e5;

void solve()
{
    int n;
    cin >> n;
    vector<long long> cnt(N+1, 0), dp(N+1, 0);
    for(int i = 0; i<n; i++)
    {
        int ele;
        cin >> ele;
        cnt[ele]++;
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    for(long long i = 2; i<=N; i++)
    {
        dp[i] = max(cnt[i] * i + dp[i-2] , dp[i-1]);
    }
    cout << dp[N] << endl;
}

int main()
{
    fastio();
    int t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}