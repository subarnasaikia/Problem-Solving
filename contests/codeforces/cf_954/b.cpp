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

#define int long long
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
    int n=nxt(), m=nxt(), mx = 0;
    vvll v(n, vll(m));
    rep(i,n) rep(j,m) cin>>v[i][j];

    if(n == 1 || m == 1)
    {
        if(n==1 && m==1){
            cout << v[0][0] << endl;
            return;
        }
        if(n==1)
        {
            v[0][0] = min(v[0][0] , v[0][1]);
            rep(i,m-2)
            {
                int *ele = &v[0][i+1];
                if(*ele > v[0][i] && *ele > v[0][i+2])
                    *ele = max(v[0][i], v[0][i+2]);
            }
            v[0][m-1] = v[0][m-2] < v[0][m-1] ? v[0][m-2] : v[0][m-1];
            rep(j,m)
            {
                cout << v[0][j] << " ";
            }
            cout << endl;   
            return;
        }
        if(m==1)
        {
            v[0][0] = min(v[0][0], v[1][0]);
            rep(i,n-2)
            {
                int *ele = &v[i+1][0];
                if(*ele > v[i][0] && *ele > v[i+2][0])
                    *ele = max(v[i][0], v[i+2][0]);
            }
            v[n-1][0] = v[n-2][0] < v[n-1][0] ? v[n-2][0] : v[n-1][0];
            rep(j,n)
            {
                cout << v[j][0] << endl;
            }
            return;
        }
    }

    rep(i,n) 
    {
        rep(j,m)
        {
            int *ele = &v[i][j];
            // cout << i << " " << j << " " << *ele << endl;
            
            if( (i == 0 || i == n-1) && ( j != 0 && j != m-1 ) )
            {
                if( (*ele > v[i][j-1]) && (*ele > v[i][j+1]))
                {
                    if(i==0 && *ele > v[i+1][j])
                        *ele = max(v[i][j-1], max(v[i][j+1], v[i+1][j]));
                    else if(i==n-1 && *ele > v[i-1][j])
                        *ele = max(v[i][j-1], max(v[i][j+1], v[i-1][j]));
                }
            }
            else if( (j == 0 || j == m-1) && (i != 0 && i != n-1) )
            {
                if( (*ele > v[i-1][j]) && (*ele > v[i+1][j]))
                {
                    if(j==0 && *ele > v[i][j+1])
                        *ele = max(v[i-1][j], max(v[i+1][j], v[i][j+1]));
                    else if(j==m-1 && *ele > v[i][j-1])
                        *ele = max(v[i+1][j], max(v[i-1][j], v[i][j-1]));
                }
            }
            else if((i==0 && j==0)){
                if(( *ele > v[i][j+1]) && (*ele > v[i+1][j])) 
                    *ele = max(v[i][j+1], v[i+1][j]);
            }
            else if(i==0 && j==m-1){
                if((*ele > v[i][j-1]) && (*ele > v[i+1][j]))
                    *ele = max(v[i][j-1], v[i+1][j]);
            }
            else if(i==n-1 && j==0){
                if((*ele > v[i-1][j]) && (*ele > v[i][j+1]))
                    *ele = max(v[i-1][j], v[i][j+1]);
            }
            else if(i==n-1 && j==m-1){
                if((*ele>v[i][j-1]) && (*ele > v[i-1][j]))
                    *ele = max(v[i][j-1], v[i-1][j]);
            }
            else {
                if( (*ele > v[i-1][j]) &&
                    (*ele > v[i][j-1]) &&
                    (*ele > v[i+1][j]) &&
                    (*ele > v[i][j+1]))
                    *ele = max(v[i-1][j], max(v[i][j-1], max(v[i+1][j], v[i][j+1]) ));
            }
            // cout << i << " " << j << " " << *ele << endl;
        }
    }
    rep(i,n)
    {
        rep(j,m)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
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