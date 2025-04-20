/*
    Author: Subarna Saikia
*/

#include <bits/stdc++.h>
using  namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#define ll long long
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair< string, string> pss;
typedef pair<string, int> psi;
typedef vector<pii> vpi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef stack<int> sti;
typedef stack<char> stc;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define int long long int
#define input() freopen("input.txt", "r", stdin);
#define output() freopen("output.txt", "w", stdout);
#define error() freopen("error.txt", "w", stderr);
#define REP(a, b, c) for(int(a) = (b); (a) < (c); (a)++ )
#define rep(a, c) REP(a, 0, c)
#define repe(a,b,c) for(int(a) = (b); (a) <= (c); (a)++)
#define repl(a,b,c) for(ll(a) = (b); (a) < (c); (a)++)
#define repd(a, b, c) for(int(a) = (b); (a) >= (c); --(a));
#define RESET(a,b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define lb(a) lower_bound(all(v), a)
#define ub(a) upper_bound(all(v),a)
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define allg(v) all(v), greater<int>()
#define permute next_permutation
#define sb(n) __builtin_popcount(n)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define endl '\n'
#define line cout<<endl;
// const int MAX = 9223372036854775807;

int nxt(){
    int n;
    cin >> n;
    return n;
}


void solve(){
    // Main solution goes here
    int a[3];
    rep(i,3) cin>>a[i];
    sort(a, a+3);
    int add = 5;
    if(a[1] - a[0] >= add-1){
        a[0] += add;
        // cout << "a[0] = " << a[0] << endl;
            cout << a[0] * a[1] * a[2] << endl;
            return;
    }
    else {
        add = add - (a[1] - a[0]);
        a[0] = a[1];
        if(add == 1){
            cout << (a[0] + 1) * a[1] * a[2] << endl;
            return;
        }
        if(add == 2 )
        {
            cout << pow(a[0] + 1, 2) * a[2] << endl;
            return;
        }
        if(add == 3)
        {
            if(a[0] < a[2])
            {
                cout << (a[0] + 2) * (a[1] + 1) * a[2] << endl;
                return;
            }
            else {
                cout << pow(a[0]+1, 3) << endl;
                return ;
            }
        }
        if(add == 4)
        {
            if(a[0] == a[2])
            {
                cout << pow(a[0] + 1, 2) * (a[2] + 2) << endl;
                return;
            }else {
                cout << pow(a[0]+2, 2) * a[2] << endl;
                return;
            }
        }
        if(add == 5)
        {
            if(a[0] == a[2])
            {
                cout << pow(a[0] + 2, 2) * (a[2] + 1) << endl;
                return;
            }
            if (a[0] == a[2] - 1) {
                cout << pow(a[2] + 1, 3) << endl;
                return;
            }
            cout << (a[0] + 3) * (a[1]+2) * (a[2]) << endl;
            return;
        }
    }
}

signed main(){
    fastio();

    #ifdef ONLINE_JUDGE
    // input(); output(); error();
    #endif

    int tc=1;
    cin>>tc;
    while (tc--) solve();

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;

}