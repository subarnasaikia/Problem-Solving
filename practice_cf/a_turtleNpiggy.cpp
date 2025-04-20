#include <bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#define ll long long

void solve()
{
    int l, x;
    cin >> l >> x;
    cout << floor(log2(x)) << endl;
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

