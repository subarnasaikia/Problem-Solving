#include<bits/stdc++.h>
using namespace std;

template<typename t>
void print(t a, string msg = "")
{
    // cout << msg << " : "<<a << endl;
}
void getVect(vector<int> &a)
{
    for(auto &i : a) cin >> i;
}
void printVect(vector<int> &a)
{
    for(auto &i: a) cout << i <<" ";
    cout << endl;
}


int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    getVect(c);
    sort(c.begin(), c.end(), greater<int>());
    
    function<int(int, int)> miniCoin = [&](int i, int coinLeft){
        if(i == n-1)
        {
            if(!(coinLeft % c[i])) return coinLeft/c[i];
            else return -1;
        }
        if(coinLeft == 0) return 0;
        if(c[i] > coinLeft) return miniCoin(i+1, coinLeft);
        int j = floor(coinLeft/c[i]);
        int coins = INT_MAX;
        bool isPossible = false;
        print<int>(i, "i ");
        while(j>= 0)
        {
            print<int>(j, "j ");
            int temp =miniCoin(i+1, coinLeft - (j*c[i]));
            print<int>(temp, "temp ");
            if(isPossible && (temp == -1 || temp >coins)) break;
            if(temp != -1){
                coins = min(coins, temp + j);
                print<int>(coins, "coins ");
                isPossible = true;
            }
            j--;
        }
        if(isPossible) print<int>(coins, "Coins");
        if(isPossible) return coins;
        return -1;
    };
    // print<int>(miniCoin(0, x));
    cout << miniCoin(0, x) << endl;
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}