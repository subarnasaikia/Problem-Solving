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
const int N = 407;
int n, m;
map<int, vector<int>> graph;
map<int, vector<int>> graph2;
int vis[N];
int dist[N];
void bfs()
{
    RESET(vis, 0);
    queue<int> q;
    dist[0] = 0;
    vis[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        vis[u] = 1;
        q.pop();
        for(int v: graph[u])
        {
            if(vis[v]) continue;
            if(dist[v] == -1)
            {
                dist[v]  = dist[u] +1;
                q.push(v);
            }
        }
    }
}

void constructG()
{

}

void solve(){
    // Main solution goes here
    RESET(dist, -1);
    n=nxt(), m=nxt();
    rep(i, m)
    {
        int u=nxt()-1, v=nxt()-1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int flag = 1;
    for(int v : graph[0])
    {
        if(v == n-1)
        {

        }
    }
    bfs();
    cout<<dist[n-1]<<endl;

}

signed main(){
    fastio();

    #ifdef ONLINE_JUDGE
    //input(); output(); error();
    #endif

    int tc=1;
    // cin>>tc;
    while (tc--) solve();

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;

}