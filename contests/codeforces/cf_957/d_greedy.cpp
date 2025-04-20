#include <bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#define ll long long

void solve()
{
    int n, m, k;
    cin >> n >> m >>k;
    string s;
    cin >> s;
    
    //greedy solution
    vector<int> log;
    for(int i = 0; i<n; i++)
        if(s[i] == 'L')
            log.push_back(i);
    log.push_back(n);
    int cell = -1, logInd = 0, swim = 0;
    while(cell < n)
    {
        if(cell == -1 || (cell != -1 && s[cell] == 'L'))
        {
            // cout << "cell: " << cell << endl;
            if(cell + m >= log[logInd] ){
                cell = log[logInd++];
                // cout << "log: " << cell << endl;
                // cout << "logInd: " << logInd << endl;
            }
            else {
                if(s[cell + m ] == 'C') return void(cout<<"NO\n");
                // swim++;
                cell += m;
                // cout << "cell, swim: " << cell << " "<< swim << endl;
            }
        }
        else{
            if(s[cell] == 'C') return void(cout << "NO\n");
            swim++;
            cell++;
            // cout << "cell, swim: " << cell << " "<< swim << endl;
        }
    }
    // cout << "swim: "<<swim << endl;
    cout << (swim <= k ? "YES\n": "NO\n");
}

int main()
{
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}

