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
    vll a(n); rep(i, n) cin >> a[i];
    vll prefix_sum(n, 0);
    prefix_sum[0] = a[0];
    REP(i, 1, n)
    {
        prefix_sum[i] = prefix_sum[i-1] + a[i]; 
    }
    auto getSum = [](int k) -> int {
        return k*(k+1)/2;
    };
    auto getR = [&](int l , int u) -> int
    {
        int start = l, end = n-1;
        int prev = (l > 0) ? prefix_sum[l-1] : 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if((prefix_sum[mid] - prev) > (u-1)) end = mid-1;
            else start = mid+1;
        }
        int score1 =getSum(u) - getSum(u - (prefix_sum[end] - prev));
        int score2 =(end+1 < n) ? (getSum(u) - getSum((prefix_sum[end+1] - prev) - u - 1)) : 0;
        if(score1 >= score2) return end >= l ? end : l;
        return (end+1 < n) ? end + 1 : end;
    };
    int q=nxt();
    while(q--)
    {
        int l=nxt() - 1, u=nxt();
        cout << getR(l, u) + 1 << " ";
    }
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