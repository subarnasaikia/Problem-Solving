#include<bits/stdc++.h>
using namespace std;

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
    sort(c.begin(), c.end(), greater<int>());
    vector<long long> dp(x+1, 10e9);
    dp[0] = 0;
    for(int i =1; i <= x; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i-c[j]] + 1);
        }
    }
    cout << (dp[x] == 10e9 ? -1 : dp[x] )<< endl;

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}