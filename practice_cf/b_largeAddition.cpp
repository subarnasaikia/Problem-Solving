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
    ll n;
    cin >> n;
    if(n%10 == 9) return void(cout<<"NO\n");
    n /=10;
    while(n>0)
    {
        if(n == 1) return void(cout << "YES\n");
        if(n%10 == 0) return void(cout<<"NO\n");
        n/=10;
    }
    cout << "NO\n";
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

