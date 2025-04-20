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
    cin >> n >> k >> m;
    string s;
    cin >> s;
    
    //greedy solution
    vector<int> log(n+1, 0);
    int lastLog = -1;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == 'L') lastLog = i;
        log[i] = lastLog;
    }
    int steps = -1;
    bool isInWater = false;
    while (steps< n)
    {
        if(isInWater)
        {
            steps++;
            if(steps >= n) return void(cout <<"YES\n");
            if(s[steps] == 'C') return void(cout<<"NO\n");
            if(s[steps] == 'W')
            {
                if(m <= 0) return void(cout<<"NO\n");
                m--;
                continue;
            }
            if(s[steps] == 'L')
            {
                isInWater = false;
                continue;
            }
        }
        int nextSteps = steps + k;
        if(k == 0) nextSteps +=1;
        if(nextSteps >= n) return void(cout <<"YES\n");
        if(s[nextSteps] == 'L'){
            steps = nextSteps;
            continue;
        }
        if(s[nextSteps] == 'C' ){
            if(steps < log[nextSteps]){
                steps = nextSteps;
                continue;
            }else return void(cout<<"NO\n");
        }
        if(s[nextSteps] == 'W')
        {
            if(steps < log[nextSteps]){
                steps = nextSteps;
                continue;
            }else{
                if(m<= 0) return void(cout<<"NO\n");
                m--;
                steps = nextSteps;
                isInWater = true;
                continue;
            }
        }
    }
    cout << "YES\n" << endl;

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

