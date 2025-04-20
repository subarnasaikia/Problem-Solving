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
    int n=nxt(), q=nxt();
    vll p(n), mini(n), maxi(n);
    int m = 0;
    rep(i, n)
    {
        cin >> p[i];
        m = max(m, p[i]);
        maxi[i] = m;
    }
    string s;
    cin >> s;
    mini[n-1] = p[n-1];
    for(int i = n-2; i>= 0 ; i--)
    {
        mini[i] = min(mini[i+1], p[i]);
    }
    auto isProblamatic = [&](int ind) -> bool
    {
        if(s[ind] == 'R' && s[ind-1] == 'L')
        {
            if(maxi[ind - 1] > ind || mini[ind] < ind+1) return true;
        }
        if(s[ind] == 'L' && s[ind + 1] == 'R')
        {
            if(maxi[ind] > ind+1 || mini[ind+1] < ind +2) return true;
        }
        return false;
    };
    int problamaticLR = 0;
    REP(i, 1, n-1)
    {
        // if(isProblamatic(i)) problamaticLR++;
        if(s[i] == 'L' && s[i+1] == 'R')
        {
            if(maxi[i] > i+1 || mini[i+1] < i+2)
            {
                problamaticLR++;
            }
        }
    }
    while(q--)
    {
        int l = nxt() - 1;
        bool p1 = isProblamatic(l);
        if(s[l] == 'R') s[l] = 'L';
        else s[l] = 'R';
        bool p2 = isProblamatic(l);
        // cout << s << endl;
        // cout << p1 << " " << p2 <<  endl;
        if(p1  && !p2) problamaticLR--;
        if(!p1 && p2) problamaticLR++;
        if(problamaticLR == 0) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
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