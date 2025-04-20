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
    string s;
    cin >> s;
    // vi indexOfn;
    int cnt = 0;
    rep(i, s.size() - 3)
    {
        if(s[i] != '1') continue;
        string ss = "100";
        int k = 0;
        bool ok = true;
        for(int j = i+1; j<i+4; j++)
        {
            if(s[j] != ss[k]) {ok = false; break;}
            k++;
        }
        if(ok) cnt++; 
    }
    auto check = [&](int ind) -> bool {
        bool ok = false;
        // string s1 = "1100";
        if(s[ind] == '1')
        {
            if(ind >= s.size()-2) return false;
            if(s[ind+1] == '1' && s[ind+2] == '0' && s[ind+3] == '0') return true;
            else if(ind == 0) return false;
            else {
                if(s[ind - 1] == '1' && s[ind+1] == '0' && s[ind+2] == '0') return true;
                else return false;
            }
        }
        if(ind <= 1) return false;
        if(s[ind-1] == '1' && s[ind -2] == '1' && s[ind+1] == '0') return true;
        if(ind == 2) return false;
        if(s[ind-1] == '0' && s[ind-2] == '1' && s[ind-3] == '1') return true;
        return false;
    };
    // cout << cnt << endl;
    int q=nxt();
    while(q--)
    {
        int ind = nxt() - 1;
        char v; cin >> v;
        bool c1 = check(ind);
        s[ind] = v;
        bool c2 = check(ind);
        if(c1 && !c2) cnt--;
        if(!c1 && c2) cnt++;
        // cout << s << endl;
        // cout << c1 << " " << c2 << endl;
        // cout << cnt << endl;
        if(cnt > 0 ) cout<< "YES\n";
        else cout << "NO\n";
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