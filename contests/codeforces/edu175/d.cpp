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
const int MOD = 998244353;

int nxt(){
    int n;
    cin >> n;
    return n;
}


void solve(){
    // Main solution goes here
    int n=nxt();
    map<int, vector<int>> tree;
    rep(i, n-1)
    {
        int p = nxt();
        tree[p].push_back(i+2);
        tree[i+2].push_back(p);
    }

    queue<int> q, q1;
    vector<int> level(n+1, 0), visited(n+1, 0);
    q.push(1);
    visited[1] = 1;
    int l = 0;
    while(!q.empty())
    {
        level[l] = q.size();
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v: tree[u])
            {
                if(!visited[v])
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        l++;
    }
    int ans = 0;
    for(auto &vis: visited) vis = 0;
    q1.push(1);
    visited[1] = 1;
    l = 0;
    while(!q1.empty())
    {
        int levelTotal = level[l+1];
        while(!q1.empty())
        {
            int u = q1.front();
            q1.pop();
            for(auto v: tree[u])
            {
                if(!visited[v])
                {
                    visited[v] = 1;
                    int sss  = tree[v].size() - 1;
                    ans += (levelTotal - sss);
                    ans = ans % MOD;
                    q1.push(v);
                }
            }
        }
        l++;
    }
    for(auto l: level) cout << l << " ";
    cout << endl;
    cout << (ans + tree[1].size()) % MOD << endl;

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