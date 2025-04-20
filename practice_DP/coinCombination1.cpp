#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

template<typename t>
void print(t a, string msg = "")
{
    cout << msg << " : "<<a << endl;
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
    long long n, x;
    cin >> n >> x;
    vector<int> c(n);
    getVect(c);
    vector<long long> dp(x+1);
    dp[0] = 1;
    for(int i =1; i <= x; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i - c[j] >= 0)
                dp[i] += dp[i-c[j]] % MOD; 
        }
    }
    cout << dp[x]%MOD << endl;

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}