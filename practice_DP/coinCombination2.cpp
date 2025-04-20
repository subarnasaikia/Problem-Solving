#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

template<typename t>
void print(t a, string msg = "")
{
    // cout << msg << " : "<<a << endl;
}
void getVect(vector<int> &a)
{
    for(auto &i : a) cin >> i;
}
void printVect(vector<int> &a)
{
    for(auto &i: a) cout << i <<" ";
    cout << endl;
}


int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    getVect(c);
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    dp[0][0] = 1;
    // function<int(int, int)> coinCombinations = [&](int i, int sum)
    // {
    //     if(sum == 0) return 1;
    //     if(i == n) return 0;
    //     if(dp[i][sum] > 0) return dp[i][sum];
    //     int skip = coinCombinations(i+1, sum);
    //     if(sum >= c[i]) dp[i][sum]= (skip + coinCombinations(i, sum-c[i]))%MOD;
    //     return dp[i][sum];
    // };
    // cout << coinCombinations(0, x)%MOD << endl;

    for(int i = 0; i<n; i++) dp[i][0] = 1;
    for(int i = n-1; i>= 0; i--)
    {
        for(int j = 1; j<= x; j++)
        {
            int skip = dp[i+1][j];
            int cur = 0;
            if(j >= c[i]) cur = dp[i][j-c[i]];
            dp[i][j] = (skip + cur)%MOD;
        }
    }
    cout << dp[0][x] << endl;

    clog<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}