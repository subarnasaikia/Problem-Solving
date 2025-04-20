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


void solve(){
    // Main solution goes here
    int n=nxt(), x=nxt(), cont = 0;
    for(double i = 1; i<ceil(x/3.0); i++)
    {
        if(0.0 <= (n/(i*i)- x/i)) cont++;
        int c = n - x + i;
        cont += c*3;
        int bc = n - i*x + i*i;


    }
    // for(int i = 1; i<=ceil(x/3.0); i++)
    // {
    //     for(int j = i; j+i<=ceil(x/2.0); j++)
    //     {
    //         for(int k = j; k+j+i<=x; k++)
    //         {
    //             int N = i*j + i*k +  j*k;
    //             if(N<= n)
    //             {
    //                 if(i == j && j == k) {cont++; continue;}
    //                 unordered_set<int> st;
    //                 st.insert(i);
    //                 st.insert(j);
    //                 st.insert(k);
    //                 if(st.size() == 2)
    //                 {
    //                     cont += 3;
    //                 }else cont += 6;
    //             }
    //         }
    //     }
    // }
    cout << cont << endl;
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