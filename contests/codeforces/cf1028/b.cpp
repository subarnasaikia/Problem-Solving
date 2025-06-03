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


namespace sub{
    /**
     * @brief To find the power. Ref: https://cp-algorithms.com/algebra/binary-exp.html
     * 
     * @param x 
     * @param n 
     * @return long long 
     */
    long long power(long long x, long long n)
    {
        long long ans = 1;
        while(n > 0)
        {
            if(n & 1ll)
                ans *= x;
            x *= x;
            n >>= 1ll;
        }
        return ans;
    }

    /**
     * @brief To find the power with MOD. ref: https://cp-algorithms.com/algebra/binary-exp.html
     * 
     * @param x 
     * @param n 
     * @param MOD 
     * @return long long 
     */
    long long powerMOD(long long x, unsigned long long n, long long MOD = 1e9+7)
    {
        long long ans = 1;
        x %= MOD;
        if(x == 0) return 0; // if x is divisible by MOD
        while(n > 0)
        {
            if(n & 1ll)
                ans = (ans*x) % MOD;
            x = (x*x) % MOD;
            n >>= 1ll;
        }
        return ans;
    }
}

long long MOD = 998244353;

int nxt(){
    int n;
    cin >> n;
    return n;
}


void solve(){
    // Main solution goes here
    int n=nxt();
    vector<int> p(n), q(n), r(n);
    rep(i, n) cin>> p[i];
    rep(i, n) cin>> q[i];
    int maxp = -1, maxIndp = -1, maxq = -1, maxIndq = -1;
    rep(i, n){
        if(maxp < p[i]){
            maxp = p[i];
            maxIndp = i;
        }
        if(maxq < q[i]){
            maxq = q[i];
            maxIndq = i;
        }
        int r1 = (sub::powerMOD(2, maxp, MOD) + sub::powerMOD(2, q[i - maxIndp], MOD)) % MOD;
        int r2 = (sub::powerMOD(2, p[i - maxIndq], MOD) + sub::powerMOD(2, maxq, MOD)) % MOD;
        if(maxp < maxq){
            r[i] = r2;
        } else if(maxp > maxq){
            r[i] = r1;
        } else {
            if( q[i - maxIndp] < p[i - maxIndq] ){
                r[i] = r2;
            } else{
                r[i] = r1;
            } 
        }
    }
    rep(i, n) cout << r[i] << " ";
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