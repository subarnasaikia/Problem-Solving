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

vector<int> v;
void solve(){
    // Main solution goes here
    v.clear();
    int n=nxt();
    // vector<int> v = {n};
    v.push_back(n);
    if(n == 1)
    {
        cout << 1 << endl << 1 << endl;
        return;
    }
    int bits = floor(log2(n)) + 1;
    if(pow(2, bits-1) == n)
    {
        cout << 1 << endl << n << endl;
        return;
    }
    // int temp = n;
    // int i = 0;
    for(int bit = 0; bit < 64; bit++)
    {
        if(n& (1LL << bit))
        {
            int b = 1LL << bit;
            int current = n & (~b);
            v.push_back(current); 
        }
    }
    // while(bits > 0)
    // {
    //     // if(temp%2 == 1)
    //     // {
    //     //     int diff = pow(2, i);
    //     //     v.push_back(n - diff);
    //     // }

    //     i++;
    //     temp = temp >> 1LL;
    //     bits--;
    // }
    cout << v.size() << endl;
    for(int i = v.size() -1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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