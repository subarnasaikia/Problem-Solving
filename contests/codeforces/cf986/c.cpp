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
    int n=nxt(),m=nxt(), v=nxt();
    vll a(n);
    rep(i, n) cin>>a[i];
    vll leftA(m+1, 0), rigthA(m+1, 0), middleA(m+1, 0);
    int ind = 0, i = 0, sum = 0;
    while(i < n)
    {
        if(ind >= m){
            while(i < n)
            {
                sum += a[i++];
            }
            leftA[ind] = sum;
            sum = 0;
            break;
        }
        sum += a[i];
        if(sum >= v)
        {
            leftA[ind++] = sum;
            sum = 0;
        }
        i++;
    }
    ind = 0, i = n-1, sum = 0;
    while(i >= 0)
    {
        if(ind >= m){
            while(i >= 0)
            {
                sum += a[i--];
            }
            rigthA[ind] = sum;
            sum = 0;
            break;
        }
        sum += a[i];
        if(sum >= v)
        {
            rigthA[ind++] = sum;
            sum = 0;
        }
        i--;
    }

    int  j = n-1;
    ind = 0 , i = 0, sum = 0;
    while(i < j)
    {
        if(ind >= m)
        {
            while(i < j)
            {
                sum += a[i++];
            }
            middleA[ind] = sum;
            break;
        }
        while(i < j && sum  < v)
        {
            sum += a[i++];
        }
        middleA[ind++] = sum;
        sum = 0;
        while(i < j && sum < v)
        {
            sum += a[j--];
        }
        middleA[ind++] = sum;
        sum = 0;
    }

    sort(all(leftA));
    sort(all(rigthA));
    sort(all(middleA));
    if(leftA[1] < v && rigthA[1] < v && middleA[1] < v)
    {
        cout << -1 << endl;
        return;
    }
    int leftAns =( leftA[0] >= v ? leftA[m] : leftA[0]);
    int rightAns = (rigthA[0] >= v ? rigthA[m] : rigthA[0]);
    int middleAns = (middleA[0] >= v ? middleA[m] : middleA[0]);
    cout << max(leftAns, max(middleAns, rightAns)) << endl;
    return;
    if(leftA[1] < v)
    {   
        if(middleA[1] < v)
        {cout << rightAns <<endl;
        return;}
        if(rigthA[1] < v)
        {
            cout << middleAns << endl;
            return;
        }
        cout << max(rightAns, middleAns) << endl;
        return;
    }
    if(rigthA[1] < v)
    {
        if(middleA[1] < v)
        {cout << leftAns << endl;
        return;}
        if(leftA[1] < v)
        {
            cout << middleAns << endl;
            return;
        }
        cout << max(middleAns, leftAns) << endl;
        return;
    }
    if(middleA[1] < v)
    {
        cout << max(leftAns, rightAns) << endl;
        return;
    }
    cout << max(leftAns, max(middleAns, rightAns)) << endl;
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