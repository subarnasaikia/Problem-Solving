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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i: a) cin >> i;
    if(a[0] == a[n-1]) return void(cout<<"NO\n");
    cout << "YES\n";
    string s(n, 'B');
    s[floor(n/2)] = 'R';
    cout << s << endl;
    // if(a[0] == a[1] || (a[0] != a[1] && a[1] != a[n-1]))
    // {
    //     cout << "R";
    //     for(int i = 1; i<n; i++) cout << "B";
    //     cout << endl;
    //     return;
    // }else {
    //     for(int i = 0; i<n-1; i++) cout << "B";
    //     cout <<"R\n";
    //     return;
    // }
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

