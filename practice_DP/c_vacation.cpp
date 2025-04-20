#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >>n;
    // vector<int> a(n), b(n), c(n);
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0; i<n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    for(int i = 0; i<3; i++) dp[0][i] = a[0][i];

    for(int x = 1; x< n; x++)
    {
        for(int i = 0; i<3; i++)
        {
            dp[x][i] =a[x][i] + max(dp[x-1][(i+1)%3], dp[x-1][(i+2)%3]);
        }
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}