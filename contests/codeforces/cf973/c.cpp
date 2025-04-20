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
    cout.flush();
    int n=nxt();
    string s="0";
    int size = 0;
    int yes=1;
    while(yes)
    {
        size++;
        s += '0';
        cout << "? " << s << endl;
        cout.flush();
        yes = nxt();
    }
    s.pop_back();
    size--;
    if(size == 0)
    {
        cout << "? " << s << endl;
        cout.flush();
        yes = nxt();
        if(!yes)
        {
            size = -1;
        }
    }
    if(size == -1)
    {
        rep(i, n){
            s += '1';
        }
        cout <<"! " << s << endl;
        cout.flush();
        return;
    }
    if(size == n-1)
    {
        cout << "! " << s << endl;
        cout.flush();
        return;
    }
    int left = 1, right = 1;
    int fL=1, fR=1;
    s+='1';
    size++;
    while(right)
    {
        if(size == n){
            s.pop_back();
            break;
        }
        cout << "? " << s << endl;
        cout.flush();
        yes = nxt();
        if(yes)
        {
            s += '1';
            size++;
            fR=0;
        }else {
            s.pop_back();
            if(fR)
            {
                size--;
                break;
            }
            s+='0';
            cout << "? " << s << endl;
            cout.flush();
            yes = nxt();
            if(yes)
            {
                size++;
                s+='1';
            }else {
                size--;
                s.pop_back();
                right = 0;
            }
        }
    }
    string str = "01";
    size = s.size()-1;
    if(size == n-1)
    {
        cout << "! " << s << endl;
        cout.flush();
        return;
    }
    while(size < n-1)
    {
        if(size == n-1){
            left = 0;
            break;
        }
        if(size + 2 >= n)
        {
            cout << "? " << '1' + s << endl;
            cout.flush();
            yes = nxt();
            if(yes)
            {
                s = '1' + s;
                size++;
                break;
            }else {
                s = '0' + s;
                size++;
                break;
            }
        }
        cout << "? " << str + s << endl;
        cout.flush();
        yes = nxt();
        if(yes)
        {
            size+=2;
            s = str + s;
        }else {
            if(size + 2 >= n)
            {
                s = '1' + s;
                size++;
                break;
            }else {
                s = "11" + s;
                size+=2;
            }
        }
    }
    cout << "! " << s << endl;
    cout.flush();
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