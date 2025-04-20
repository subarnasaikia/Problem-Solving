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
    int g=nxt(), n=nxt();
    vector<pair<int, pair<int, int>>> grazing(g), cows_alibi(n);
    for(int i = 0; i<g; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        grazing[i] = make_pair(t, make_pair(x, y));
    }
    for(int i = 0; i<n; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        cows_alibi[i] = make_pair(t, make_pair(x, y));
    }
    sort(grazing.begin(), grazing.end(), 
        [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first < b.first;
    });
    int count_innocence = 0;
    for(int i = 0; i<n; i++)
    {
        pair<int, pair<int, int>> target = make_pair(cows_alibi[i].first, make_pair(0, 0)); 
        auto next_or_cur_pos = lower_bound(grazing.begin(), grazing.end(), target, 
                                    [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
                                        return a.first < b.first;
                                });
        bool posForward = true, posBackward = true;
        if(next_or_cur_pos != grazing.end())
        {
            // cout << next_or_cur_pos->first << endl;
            int diff_time = next_or_cur_pos->first - cows_alibi[i].first;
            int x = next_or_cur_pos->second.first - cows_alibi[i].second.first;
            int y = next_or_cur_pos->second.second - cows_alibi[i].second.second;
            int distance = x*x + y*y;
            if((distance == 0ll && diff_time == 0ll))
            {
                continue;
            }
            if(!(distance <= (diff_time * diff_time) ))
                posForward = false;
        }
        if(posForward && next_or_cur_pos != grazing.begin())
        {
            next_or_cur_pos--;
            // cout << next_or_cur_pos->first << endl;
            int diff_time = abs(next_or_cur_pos->first - cows_alibi[i].first);
            int x = next_or_cur_pos->second.first - cows_alibi[i].second.first;
            int y = next_or_cur_pos->second.second - cows_alibi[i].second.second;
            int distance = (x*x) + (y*y);
            if(!(distance <= diff_time * diff_time))
                posBackward = false;
        }
        // cout << posForward << " " << posBackward << endl;
        if(!posForward || !posBackward) count_innocence++;
    }
    cout << count_innocence << endl;

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