#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for(int& v: h) cin >> v;
    for(int& v: s) cin >> v;
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<= x; j++)
        {
            dp[i][j] = dp[i-1][j];
            int left = j - h[i-1];
            if(left >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][left] + s[i-1]);
            }
        }
    }
    cout << dp[n][x] << endl;
}