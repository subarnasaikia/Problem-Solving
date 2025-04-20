#include <bits/stdc++.h>
using  namespace std;

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
    int n =nxt(), q=nxt();
    string a, b;
    cin >> a>>b;
    unordered_map<char, int> am, bm;
    vector<int> dp(n+1, 0);
    if(a[0] == b[0]) dp[0]  = 0;
    else{ dp[0] = 1;
        am[a[0]]++;
        bm[b[0]]++;
    }

    for(int i = 1; i<n; i++)
    {
        if(a[i] == b[i]){
            dp[i] = dp[i-1];
        }else{
            dp[i] = dp[i-1];
            if(am[b[i]] > 0 || bm[a[i]] > 0)
            {
                dp[i] -= 1;
                // if(am[b[i]] > 0){ am[b[i]]--;}
                // else bm[a[i]]--;
                if(am[b[i]] > 0 && bm[a[i]] > 0)
                {
                    am[b[i]]--;
                    bm[a[i]]--;
                }else if(am[b[i]] > 0){
                    am[b[i]]--;
                    am[a[i]]++;
                }else {
                    bm[b[i]]++;
                    bm[a[i]]--;
                }
            }else{ 
                dp[i]++;
                am[a[i]]++;
                bm[b[i]]++; 
            }
        }
    }
    while(q--)
    {
        int ans = 0, l=nxt(), r=nxt();
        if(l == 1) {
            ans = dp[r-1];
        }else ans = abs(dp[l-2] - dp[r-1]);
        cout << ans << endl;
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