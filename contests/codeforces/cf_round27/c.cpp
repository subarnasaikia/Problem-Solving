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
    int temp = n;
    vll a;
    int l = 1, p = 1;
    // a.push_back(1);
    while((p << l) < n)
    {
        l++;
    }
    l -= 1;
    if((n&1) || (n == (p << (l+1))))
    {
        if(n == ( p << (l+1)))
        {
            a.push_back(n);
            n--;
        }
        a.push_back(n);
        a.push_back(n - 1);
        a.push_back(3);
        a.push_back(1);
        int in = 2;
        while(in <= n)
        {
            if(in != n && in != n-1 && in != 3)
            {
                a.push_back(in);
            }
            in++;
        }
    }else{
        int odd = p << l;
        a.push_back(odd - 1);
        a.push_back(odd);
        a.push_back(odd+1);
        int in = 1;
        while(in <= n)
        {
            if(in != odd -1 && in != odd && in != odd + 1)
            {
                a.push_back(in);
            }
            in++;
        }
    }
    reverse(all(a));
    int k = 0;
    rep(i, temp)
    {
        if(i&1)
        {
            k |= a[i];
        }else{
            k &= a[i];
        }
    }
    cout << k << endl;
    rep(i, temp)
    {
        cout << a[i] << " ";
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