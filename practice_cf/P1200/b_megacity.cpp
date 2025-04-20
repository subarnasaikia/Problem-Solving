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

const int M = 1000*1000;

void solve(){
    // Main solution goes here
    cout << fixed << setprecision(7) ;
    map<int, int> points;
    int n=nxt(), s=nxt();
    rep(i, n)
    {
        int x=abs(nxt()), y=abs(nxt()), k=abs(nxt());
        int distance = x*x + y*y;
        points[distance] += k;
    }
    int sizeOfuniqueDistance = points.size();
    vll prefix_sum(sizeOfuniqueDistance), unique_distances(sizeOfuniqueDistance);
    int i=0;
    for(auto point: points)
    {
        unique_distances[i] = point.first;
        if(i  == 0)
        {
            prefix_sum[i] = point.second;
        }else {
            prefix_sum[i] = prefix_sum[i-1] + point.second;
        }
        i++;
    }
    int left = 0, right = sizeOfuniqueDistance-1;
    while (left < right)
    {
        int mid = left + (right - left)/2;
        if((prefix_sum[mid] + s) >= M) {
            right = mid;
        }else left = mid + 1;
    }
    if((prefix_sum[left] + s) < M) return void(cout << -1 << endl);
    long double dist = static_cast<long double>(unique_distances[left]);
    long double ans = sqrtl(dist);
    cout << ans << endl;
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