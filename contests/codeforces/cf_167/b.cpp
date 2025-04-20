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

int sbtr(string b, string s){
    int middle, mid;
    if(s.empty()) return 0;
    auto i = b.find(s);
    if(i != string::npos) return s.size();
    int left = sbtr(b, s.substr(0, s.size() - 1));
    int right = sbtr(b, s.substr(1, s.size()));
    string ss = s.substr(0,(s.size()/2 + 1)) + s.substr(s.size()/2 + 1, s.size());
    middle = sbtr(b, ss);
    if(s.size()%2 == 0){
        string ss = s.substr((0,(s.size()/2))) + s.substr(s.size()/2, s.size());
        mid = sbtr(b, ss);
    }
    middle = max(mid, middle);
    return max(left, max(right, middle));
}

void solve(){
    // Main solution goes here
    string a, b;
    cin>> a>> b;
    int la= a.size(), ans = 0 , lb = b.size();
    // for(auto s:b)
    // {
    //     auto i = a.find(s);
    //     if(i != string::npos)
    //     {
    //         a = a.substr(i, la - (int)i);
    //     }else ans++;
    // }
    int sb = sbtr(b, a);
    ans = la + lb -sb;
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