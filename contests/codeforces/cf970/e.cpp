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

int findMax(map<char, int> &mp)
{
    int ans = INT_MIN;
    for(auto m: mp)
    {
        ans = max(ans, m.second);
    }
    return ans;
}
int findMin(map<char, int> &mp)
{
    int ans = INT_MAX;
    for(auto m: mp)
    {
        ans = min(ans, m.second);
    }
    return ans;
}


void solve(){
    // Main solution goes here
    int n =nxt();
    string s;
    cin >> s;
    map<char, int> even, odd;
    if(n == 1 || n==3) return void(cout << 1 << endl);
    if(n == 2 ) return void(cout << 0 << endl);
    rep(i, n)
    {
        if(i&1)
        {
            even[s[i]]++;
        }else odd[s[i]]++;
    }
    if(even.size() == 1 && odd.size() == 1) {
        cout << ((n&1) ? 1: 0) << endl;
    }
    int ansE = 0, ansO = 0;
    if(even.size() == 2)
    {
        ansE = findMin(even);
    }else{
        int maxi = findMax(even);
        ansE =(n/2) - maxi;
    }
    if(odd.size() == 2)
    {
        ansO = findMin(odd);
    }else {
        int maxi = findMax(odd);
        ansO = (n/2 ) - maxi ;
    } 
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