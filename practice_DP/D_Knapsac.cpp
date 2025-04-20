#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int N = 105, W = 100000+5;
vector<ll> w(N), v(N);
vector<vector<ll>> dp(N+1, vector<ll>(W+1, -1));

ll Knapsack(int i, int weight_taken)
{
    if(i == N) return 0;
    if(weight_taken  == W) return 0;
    if(dp[i][weight_taken] != -1) return dp[i][weight_taken];

    ll ans  = Knapsack(i+1, weight_taken);
    if(weight_taken + w[i] <= W)
    {
        ans = max(ans, v[i] +  Knapsack(i+1, weight_taken + w[i]));
    }
    dp[i][weight_taken] = ans;
    return dp[i][weight_taken];
}

int main()
{
    cin >> N >> W;
    for(int i = 0; i<N; i++)
    {
        cin >> w[i] >> v[i];
    }
    ll ans = Knapsack(0, 0);
    cout << ans << endl;
    return 0;
}