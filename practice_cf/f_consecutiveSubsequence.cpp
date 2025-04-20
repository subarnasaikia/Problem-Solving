#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), ind;
    for(int &i: a) cin >> i;
    map<int, int> dp;
    int ans = 0, cur = -1;
    for(int i=0; i<n; i++)
    {
        int x = a[i];
        dp[x] = dp[x-1] + 1;
        if(dp[x] > ans)
        {
            ans = dp[x];
            cur = x;
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        if(a[i] == cur){
            ind.push_back(i+1);
            cur--;
        }
    }

    cout << ans << endl;
    for(int i=ans-1; i>= 0; i--)
    {
        cout << ind[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}