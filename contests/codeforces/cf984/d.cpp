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
    int n=nxt(), m=nxt();
    vector<vector<char>> grid(n, vector<char>(m));
    
    rep(i, n) rep(j, m) {cin >> grid[i][j];}
    int ans = 0;
    int k = (min(n, m) + 1 )/ 2;
    vector<char> curet[k];
    rep(i, k)
    {
        for(int j = i; j<m - i; j++)
        {
            curet[i].push_back(grid[i][j]);
        }
        for(int j = i+1; j<n-i; j++)
        {
            curet[i].push_back(grid[j][m-i-1]);
        }
        for(int j = m-i-2; j>= i; j--)
        {
            curet[i].push_back(grid[n-i-1][j]);
        }
        for(int j=n-i-2; j>= i+1; j--)
        {
            curet[i].push_back(grid[j][i]);
        }
    }
    // cout << k << endl;
    // rep(i, k) {rep(j, curet[i].size())
    // {
    //     cout << curet[i][j];
    // }
    // cout << endl;}
    rep(i, k)
    {
        int size = curet[i].size();
        rep(j, size)
        {
            if(curet[i][j] != '1') continue;
            string ss = "543";
            int ind = 0;
            bool ok = true;
            for(int l = (j+1); l<(j+4); l++)
            {
                if(ss[ind] != curet[i][l%size]){
                    ok = false; 
                    break;
                }
                ind++;
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
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