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
    int n =nxt(), k=nxt();
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vll sortedA(all(a));
    sort(all(sortedA));
    int midInd = n/2 - 1;
    int maxAns = 0;
    bool isOne = false;
    rep(i, n) {
        if(b[i] == 1) {
            isOne = true;
            break;
        }
    }
    if(!isOne)
    {
        maxAns = sortedA[n-1] + sortedA[midInd];
        cout << maxAns << endl;
        return ;
    }
    bool isMidOne = false, isMid1One= false;
    rep(i, n)
    {
        if(a[i] == sortedA[midInd]){
            if(b[i] == 1){
                isMidOne = true;
            }
        }
        if(a[i] == sortedA[midInd+1])
        {
            if(b[i] == 1)
            {
                isMid1One = true;
            }
        }
    }
    for(int i = 0; i<n; i++)
    {
        if(b[i] == 1)
        {
            int ele = a[i] + k;
            if(ele <= sortedA[midInd])
            {
                int score = ele + sortedA[midInd + 1];
                maxAns = max(maxAns, score);
            }else {
                int score = ele + sortedA[midInd];
                maxAns = max(maxAns, score);
            }
        }else {
            int ele = a[i];
            if(ele <= sortedA[midInd])
            {
                int score = ele + sortedA[midInd + 1];
                maxAns = max(maxAns, score);
                if(isMid1One)
                {
                    int maxi = min(sortedA[midInd + 2], ele + k);
                    int score = ele + maxi;
                    maxAns = max(maxAns, score);
                }
                
            }else {
                int score = ele + sortedA[midInd];
                maxAns = max(maxAns, score);
                if(isMidOne)
                {
                    int maxi = min(sortedA[midInd + 1], ele + k);
                    int score = ele + sortedA[midInd + 1];
                    maxAns = max(maxAns, score);
                }
            }
        }
    }

    // int score = sortedA[n-1] + sortedA[midInd] + (isMidOne*k);
    // maxAns = max(maxAns, score);
    cout << maxAns << endl;


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