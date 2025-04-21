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
    int n=nxt(), k =nxt();
    vll a(n);
    int cnt = 0;
    vll cnt_k_smaller(n);
    rep(i, n)
    {
        cin >> a[i];
        if(a[i] <= k) cnt++;
        cnt_k_smaller[i] = cnt;
    }
    if(cnt < 2){
        cout << "NO\n";
        return;
    }
    int found_ind = -1;
    rep(i, n - 1)
    {
        // cout << i << " " << found_ind << endl;
        if(found_ind !=  -1)
        {
            // cout << found_ind << endl;
            int ksmall = cnt_k_smaller[i] - cnt_k_smaller[found_ind];
            // cout << ksmall <<  " " << (i - found_ind - 1)/2 + 1 << endl;
            if(ksmall >= (i - found_ind - 1)/2 + 1)
            {
                cout << "YES\n";
                return;
            }
            if(found_ind % 2 == 0 && found_ind < n - 3)
            {
                int ksmall2 = cnt_k_smaller[i] - cnt_k_smaller[found_ind + 1];
                // cout << found_ind << endl;
                // cout << ksmall2 << " " << (i - found_ind - 1- 1)/2 + 1 <<  endl;
                if(ksmall2 >= (i - found_ind - 1- 1)/2 + 1)
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
        else if( i < n-2 && cnt_k_smaller[i] >= (i/2 + 1))
        {
            if(cnt_k_smaller[i] == (i/2 + 1) && cnt == (i/2+ 1)){
                cout << "NO\n";
                return;
            }
            found_ind = i;
        }
    }
    int cnt2 = 0;
    vll cnt_arr_2(n);
    for(int i = n-1, j = 0; i>= 0; i-- , j++)
    {
        if(a[i] <= k) cnt2++;
        cnt_arr_2[j]  = cnt2;
    }

    // rep(i, n) cout << cnt_k_smaller[i] << " ";
    // cout << endl;
    // rep(i, n) cout << cnt_arr_2[i] << " ";
    // cout << endl;

    int found_ind2 = -1;
    rep(i, n-1)
    {
        // cout << i << " " << found_ind2 << endl;
        if(found_ind2 !=  -1)
        {
            int ksmall = cnt_arr_2[i] - cnt_arr_2[found_ind2];
            // cout << ksmall << endl;
            if(ksmall >= (i - found_ind2 - 1)/2 + 1)
            {
                cout << "YES\n";
                return;
            }
            if(found_ind2 % 2 == 0 && found_ind2 < n - 3)
            {
                int ksmall2 = cnt_arr_2[i] - cnt_arr_2[found_ind2 +1];
                // cout << ksmall2 << endl;
                if(ksmall2 >= (i - found_ind2 - 1- 1)/2 + 1)
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
        else if( i < n-2 && cnt_arr_2[i] >= (i/2 + 1))
        {
            if(cnt_arr_2[i] == (i/2 + 1) && cnt == (i/2+ 1)){
                cout << "NO\n";
                return;
            }
            found_ind2 = i;
        }
    }
    // cout << found_ind << " " << found_ind2 << endl;
    if((found_ind2 != -1 && found_ind != -1) && ((found_ind  + 1)< (n - found_ind2 - 1))){
        cout << "YES\n";
    }else 
        cout << "NO\n";

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