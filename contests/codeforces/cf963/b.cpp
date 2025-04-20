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
int N = 200001, MAX = 10e9+1;
vector<int> a(N);

void solve(){
    // Main solution goes here
    int n = nxt();
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    bool odd = false, even = false;
    rep(i, n)
    {
        if(!(a[i] & 1)) even = true;
        else odd = true;
    }
    if(!even || !odd)
    {
        return void(cout << 0 << endl);
    }else {
        int ans = 0, maxOdd = 1;
        for(int i = n-1; i >= 0; i--)
        {
            if((a[i] & 1) && a[i] >= maxOdd)
            {
                maxOdd = a[i];
                break;
            }
        }
        // for(int i = 0; i<n; i++)
        // {
        //     if(!(a[i] & 1))
        //     {
        //         if(a[i] < maxOdd){
        //             ans++;
        //             maxOdd += a[i];
        //             maxOdd = min(MAX, maxOdd);
        //         }else {
        //             // ans += 2;
        //             // maxOdd += (2*a[i]);
        //             // maxOdd = min(MAX, maxOdd);
        //         }
        //     }
        // }
        int it = 0;
        bool rev = false;
        int firstIt = -1;
        while(firstIt < it && it < n)
        {
            if(!(a[it] & 1)){

                if(a[it] < maxOdd)
                {
                    ans++;
                    maxOdd += a[it];
                    maxOdd = min(MAX, maxOdd);
                    if(rev) it--;
                    else it++;
                }
                else {
                    firstIt = it-1;
                    ans += 2;
                    it = n-1;
                    while((a[it] & 1)) it--;
                    maxOdd += (2*a[it]);
                    it--;
                    rev = true;
                }
            }else {
                if(rev) it--;
                else it++;
            }
        }
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