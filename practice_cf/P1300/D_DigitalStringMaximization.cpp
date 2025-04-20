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
    cin >>s;
    auto merge = [&](int l, int m, int r) {

        int n1 = m - l + 1;
        int n2 = r - m ;

        string s1="", s2="";
        for(int i = 0; i<n1; i++) s1 +=s[l+i];
        for(int j = 0; j<n2; j++) s2 +=s[m+1+j];

        int i = 0, j = 0, k = l;

        while(i < n1 && j < n2)
        {
            int num = s1[i] - '0';
            int num2 = s2[j] - '0';
            if(num< (num2 - (n1 - i)))
            {
                s[k] = (num2 - (n1 - i)) + '0';
                j++;
            }else {
                s[k] = s1[i];
                i++;
            }
            k++;
        }
        while(i < n1)
        {
            s[k] = s1[i];
            k++;
            i++;
        }
        while(j < n2)
        {
            s[k] = s2[j];
            k++;
            j++;
        }
    };

    function<void(int l, int r)> mergerSort = [&](int l , int r) {
        if (l >= r) return;

        int m = l + (r - l )/2;
        mergerSort(l, m);
        mergerSort(m+1, r);

        merge(l, m, r);
    };

    mergerSort(0, s.size()-1);
    cout << s << endl;
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