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

bool possible(string a, string b, int n)
{
    bool pos = true;
    // cout << a << endl << b <<endl;
    if(a[0] == '1' && b[1] == '1')
    {
        return false;
    }
    if(pos)
    {

        for(int i = 1; i<n-1; i++ )
        {
            if(a[i] == '0' || (a[i] == '1' && (b[i-1] == '0' || b[i+1] == '0')))
            {
                if(a[i] == '0' && b[i+1] == '1')
                {
                    b[i+1] = b[i-1];
                }
                if(a[i] == '1')
                {
                    if(b[i-1] == '0')
                    {
                        b[i-1] = '1';
                    }else{
                        b[i+1] = '1';
                    }
                }
            }else{
                pos = false;
                break;
            }
        }
    }
    if(pos)
    {
        if((a[n-1] == '1' && b[n-2] == '1'))
        {
            pos = false;
        }
    }
    // cout << a[n-1] << " " <<  b[n-2] << endl;
    return pos;
}


void solve(){
    // Main solution goes here
    int n  = nxt();
    string a, b;
    cin >> a >> b;
    string reva = a, revb = b;
    reverse(all(reva)), reverse(all(revb));
    bool pos = possible(a, b, n);
    // cout << pos << endl;
    if(!pos)
    {
        pos = possible(reva, revb, n);
        // cout << pos << endl;
    }
    cout << (pos ? "YES\n": "NO\n");
    
    
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