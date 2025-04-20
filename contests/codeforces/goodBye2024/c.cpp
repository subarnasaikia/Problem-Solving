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
    int n =nxt(), k=nxt();
    int ans = 0;
    // if( k == 1)
    // {
    //     ans = n * ( n + 1)/2;
    //     cout << ans << endl;
    //     return;
    // }
    // int small = INT32_MAX;
    // int m = n;
    // int i = 1;
    // while(m > 0)
    // {
    //     if(m < k) break;
    //     cout << i++ << endl;
    //     if(m&1)
    //     {
    //         small = 1 + (m - 1)/2;
    //         cout << small << endl;
    //     }
    //     m = (m)/2;
    // }
    // int t = n/small;
    // cout << t << endl;
    // ans = small * (t * (t+1)/2);
    // cout << ans << endl;
    if(!(k&1)) k++;
    vll a;
    function<int(int, int)> f = [&](int l, int r) -> int {
        int dist = r - l + 1;
        if(dist < k) return 0;
        int mid = l + (r - l)/2;
        if(dist&1)
        {
            // cout << mid << endl;
            a.push_back(mid);
            return mid + f(l, mid -1) + f(mid +1 , r);
        }
        return f(l, mid) + f(mid +1 , r);

    };
    ans = f(1, n);
    sort(all(a));
    rep(i, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

signed main(){
    fastio();

    #ifdef ONLINE_JUDGE
    //input(); output(); error();
    #endif

    int tc=1;
    cin>>tc;
    while (tc--) solve();

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;

}