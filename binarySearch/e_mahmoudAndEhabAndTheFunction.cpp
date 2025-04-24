/*
    Problem: https://codeforces.com/contest/862/problem/E
    Solution Author: Subarna Saikia
*/


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
    int n=nxt(), m=nxt(), q=nxt();
    int maxJ = m - n + 1;
    // cout << n << " " << m << " " << maxJ << endl;
    vll a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    int sumOfa = 0;
    vll functionJ(maxJ, 0);
    // pre calculating functionJ for second part (b arrya)
    rep(i, n){
        functionJ[0] +=  (i&1 ? -1ll*b[i] : b[i]);
        sumOfa +=  (i&1 ? -1ll*a[i] : a[i]);
    }
    if(maxJ > 1){
        rep(i, n){
            functionJ[1] +=  (i&1 ? -1ll*b[i+1] : b[i+1]);
        }
    }
    rep(j, maxJ)
    {
        if(j <= 1) continue;
        int preI = j - 2, nextI = n + j - 3;
        int preSum = b[preI] - b[preI+1];
        int nextSum = b[nextI+1] - b[nextI+2];
        nextSum *= (nextI&1 ? -1ll : 1ll);
        functionJ[j] = functionJ[j-2] - preSum + nextSum;
    }
    // rep(i, maxJ) cout << functionJ[i] << " ";
    // cout << endl;
    sort(all(functionJ));
    auto findJ = lower_bound(all(functionJ), sumOfa) - functionJ.begin();
    if(findJ >= maxJ){
        cout << abs(sumOfa - functionJ[findJ-1]) << endl;
    }else {
        cout << abs(sumOfa - functionJ[findJ]) << endl;
    }
    while(q--)
    {
        int l=nxt() - 1, r = nxt() - 1, x = nxt();
        if((r - l + 1) & 1) {
            x *= (r&1 ? -1ll: 1ll);
            sumOfa += x;
        }
        auto findJ = lower_bound(all(functionJ), sumOfa) - functionJ.begin();
        if(findJ >= maxJ){
            cout << abs(sumOfa - functionJ[findJ-1]) << endl;
            continue;
        }
        // cout << findJ-1 << " " << functionJ[findJ] << endl;
        if(findJ == 0ll){
            cout << abs(sumOfa - functionJ[findJ]) << endl;
        }else{
            // cout << abs(sumOfa - functionJ[findJ]) << " " << abs(sumOfa - functionJ[findJ-1ll]) << endl;
            cout << min(abs(sumOfa - functionJ[findJ]) , abs(sumOfa - functionJ[findJ-1ll]) ) << endl;
        }
    }
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