#include <bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#define ll long long
int flag = 0, cnt = 0;
void solve()
{
    int n, l, r;
    cin >> n>> l>>r;
    vector<int> a(n);
    for(auto&i : a) cin>> i;
    
    // if(flag)
    // {
    //     cnt++;
    //     if(cnt==475)
    //     {
    //         cout << n <<" " << l << " " << r << " "<< endl;
    //         for(auto&i: a)
    //         {
    //             cout << i<< " ";
    //         }
    //         cout << endl;
    //     }
    //     return;
    // }
    // int ans = 0, curry = 0;
    // for(auto&i :a)
    // {
    //     if(i> r) {curry = 0; continue;}
    //     if(i >= l) {
    //         ans ++;
    //         curry = 0;
    //         continue;
    //     }
    //     curry += i;
    //     if(curry >= l && curry <= r) {ans++; curry = 0;}

    // }
    // cout << ans << endl;    
}

int main()
{
    fastio();
    int t = 1;
    cin >> t;
    if(t== 10000)
    {
        flag = 1;
    }
    while(t--) solve();

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}

