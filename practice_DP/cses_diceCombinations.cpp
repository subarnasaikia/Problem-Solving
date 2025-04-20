#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long n = 1000007;
// vector<vector<long long>> dp(7, vector<long long>(n+1, 0));
vector<long long> dp(n+1, 0);
long long diceComnination(int dice_num, long long sum)
{
    if(sum == n) return 1;
    if (dp[sum] != 0 ) return dp[sum];
    
    // dice_num = 1 to 6;
    long long ans = 0;
    for(int i = 1; i<= 6; i++)
    {
        if(sum + i <= n){
            dp[sum+i] = diceComnination(i, sum + i);
            // cout <<i << " " << sum + i<< " " << dp[i][sum + i] << endl;
            ans += dp[sum+i] % MOD;
        }
    }
    // cout << ans << endl;
    return ans % MOD;
}

int main()
{
    cin >> n;
    long long ans = diceComnination(0, 0);
    cout << ans % MOD << endl;
    return 0;
}