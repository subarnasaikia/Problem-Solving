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
const int inf = 10e9;

int nxt(){
    int n;
    cin >> n;
    return n;
}


// vll dp(inf+1, 0);
void solve(){
    // Main solution goes here
    int n=nxt(), x=nxt();
    vll a(n);
    for(auto& i: a) cin>>i;
    map<int, int> mp;
    for(auto&i : a) mp[i]++;
    int cur = 0, prev = 0;
    int ans = 0;
    for(auto it: mp)
    {
        int i = it.first;
        if(i > x)
        {
            // prev = 0;
            break;
        }
        if(mp[i-1] >0)
        {
            if(it.second*i+prev > x)
            {
                int p = x/(i-1);
                if(p>= mp[i-1])
                    p = mp[i-1];
                int f = (x-(p*(i-1)))/(i);
                if(f >= it.second)
                {
                    f = it.second;
                }
                
                int ff = x/(i);
                if(ff >= it.second)
                {
                    ff = it.second;
                }
                int pp = (x-(ff*(i)))/(i-1); 
                if(pp>= mp[i-1])
                    pp = mp[i-1];
                cur = max(p*(i-1) + f*i, pp*(i-1) + ff*i);
                prev =  it.second*i;
            }
            else {cur = it.second*i+prev;
                prev = it.second*i;    
            }
        }else {
            if(it.second*i > x)
            {
                int f = x/i;
                if(f >= it.second)
                {
                    f = it.second;
                }
                cur = f*i;
            }
            else cur = it.second*i;
            prev = cur;
        }
        ans = max(ans, cur);
        if(ans == x) break;
    }
    cout << ans<< endl;
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