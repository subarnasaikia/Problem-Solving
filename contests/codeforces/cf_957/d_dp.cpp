#include <bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#define ll long long
const int INF = 10e6;

void solve()
{
    int n, m, k;
    cin >> n >> m >>k;
    string s;
    cin >> s;
    
    //dp solutions
    vector<int> dp(n+1, INF); // dp[i] = min swims requeried to reached their.
    dp[n] = 0;
    for(int i = n-1; i>= 0; i--)
    {
        if(s[i] == 'W') {
            dp[i] = dp[i+1] + 1;
        }else if(s[i] == 'L'){
            for(int j = i+1; j<min(i+m+1, n+1); j++)
            {
                dp[i] = min(dp[i], dp[j]);
            }
        }
    }
    int swim = INF;
    for(int i = 0; i<m; i++) swim = min(swim, dp[i]);
    cout << (swim <= k ? "YES\n": "NO\n");
}

int main()
{
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}

