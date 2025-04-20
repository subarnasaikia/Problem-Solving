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
    int n=nxt();
    vll a(n);
    rep(i, n) cin >> a[i];
    int x = 0;
    int m = n/2;
    vector<pair<int, pair<int, int>>> interval(m, mp(0,mp(0, 0)));
    vll b(n);
    rep(i, n)
    {
        if(x < a[i] ) x++;
        else if( x > a[i]) x--;
        b[i] = x;
    }
    if( x == n){
        cout << x - 1 << endl;
        return;
    }
    // rep(i, n) cout << b[i] << " ";
    // line
    int  j = 1, k = 0;
    while(j < n)
    {
        if(b[j - 1] <= b[j]) j++;
        else{
            int temp = j;
            while(j < n && b[j-1] >= b[j]) j++;
            interval[k++] = mp(j - temp,mp(temp, j-1));
            // cout << j - temp << " " << j << " " << temp << endl;
        }
    }
    // rep(i, m) cout << interval[i].first << " ";
    // line
    sort(all(interval));
    int skipJ = interval[m - 1].second.first, skipK = interval[m-1].second.second;
    int ansX = 0;

    rep(i, n)
    {
        if(i >= skipJ && i <= skipK) continue;
        if(ansX < a[i] ) ansX++;
        else if( ansX > a[i]) ansX--;
    }
    cout << max(ansX, maxv(b)) << endl;
    // cout << ansX << endl;

    // int neg = 0;
    // rep(i, m - 1)
    // {
    //     neg += interval[i].first;
    //     if(interval[i].first > 0) neg++;
    // }
    // int ans = n - interval[m - 1].first - neg;
    // ans = max(ans, maxv(b));
    // cout << (ans == n ? x : ans) << endl;
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