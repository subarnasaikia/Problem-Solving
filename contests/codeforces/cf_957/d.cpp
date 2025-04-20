/*
    Author: Subarna Saikia
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

bool flag = false;
int cnt = 0;
void solve(){
    // Main solution goes here
    int n=nxt(), m=nxt(), k=nxt();
    string s ;
    cin >> s;


    if(flag)
    {
        if(cnt == 147)
        {
            cout << n << " "<< m << " " << k << endl;
            cout << s << endl;
        }
        cnt++;
        return;
    }
    vll log(n);
    int logPos = -1;
    bool isInWater = false;
    rep(i,n)
    {
        log[i] = logPos;
        // cout << logPos << " ";
        if(s[i] == 'L') logPos = i;
    }
    // cout << endl;
    int startInd = -1;
    while(startInd + m < n)
    {
        if(isInWater)
        {
            startInd++;
            if(k==0 && s[startInd] == 'W')
            {
                cout << "NO\n";
                return;
            }
            if(s[startInd] == 'W')
                k--;
            else if(s[startInd] == 'C')
            {
                cout << "NO\n";
                return;
            }
            else isInWater = false;
            continue;
        }
        int next = startInd + m;
        // cout << "next " << next << endl;
        if(s[next] == 'L')
        {
            startInd = next;
            // cout << "startInd " << startInd << endl;
            continue;
        }
        else {
            int logInd = log[next];
            // cout << "logInd " << logInd << endl;
            if(logInd > startInd) startInd = logInd;
            else if(s[next] == 'C')
            {
                // cout << "C\n";
                cout << "NO\n";
                return; 
            }else {
                if(k==0)
                {
                    // cout << "K=0\n";
                    cout << "NO\n";
                    return;
                }
                k--;
                startInd = next;
                isInWater = true;
            }
            // cout << "startInd " << startInd << endl;
        }
    }
    cout << "YES\n";
}

signed main(){
    fastio();

    #ifdef ONLINE_JUDGE
    // input(); output(); error();
    #endif

    int tc=1;
    cin>>tc;
    if(tc == 10000) flag = true;
    while (tc--) solve();

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;

}