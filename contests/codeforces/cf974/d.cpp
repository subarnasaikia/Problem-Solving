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
    int n=nxt(), d=nxt(), k=nxt();
    vll a(n, 0), b(n, 0);
    while(k--)
    {
        int l=nxt() - 1, r=nxt();
        a[l] +=1;
        b[l] += 1;
        if(r < n)
        {
            a[r] -= 1;
        }
    }
    REP(i,1, n)
    {
        a[i] += a[i-1];
    }
    int maxi = a[0], ind=0;
    
    rep(i, n-d+1)
    {
        if(maxi < a[i])
        {
            maxi = a[i];
            ind = i;
        }else if(maxi == a[i])
        {
            int tempMaxi = maxi;
            for(int j = i+1; (j < (i+d)) && (j < (n)); j++)
            {
                    tempMaxi += b[j];
            }
            if(maxi < tempMaxi )
            {
                ind = i;
                maxi = tempMaxi;
            }
        }
    }

    int mini = a[0], indMini = 0;
    for(int i = 1; i<(d) && i<n; i++)
    {
        mini += b[i];
    }
    REP(i, 1, n-d+1)
    {
        if(a[i] > mini) continue;
        int tempMini = a[i];
        for(int j = i+1; j<(i+d) && j < (n); j++)
        {
            tempMini += b[j];
        }
        if(tempMini < mini)
        {
            mini = tempMini;
            indMini = i;
        }
    }


    cout << ind + 1 << " " << indMini + 1 << endl;
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