#include <bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#define ll long long

int findX(int x, int y)
{
    if(x%y != 0) return x;
    return findX(x/y, y);
}

void solve()
{
    int x , y, k;
    cin >> x>>y >> k;
    while(k>0)
    {
        int rem = x%y;
        int dif = y - rem;
        if(dif <= k) {
            x += dif;
            x = findX(x, y);
            k-=dif;
        }else {
            x += k;
            k = 0;
        }
        if(x==1){
            x = k%(y-1)+1;
            break;
        }
    }
    cout << x << endl;
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

