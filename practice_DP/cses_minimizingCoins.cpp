#include<bits/stdc++.h>
using namespace std;

#define int long long
template<typename T> 
T getMax(T a, T b)
{
    return a < b ? a : b;
}

template<typename t>
void print(t a, string msg = "")
{
    cout << msg << " : "<<a << endl;
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



signed main()
{   
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    getVect(c);

    sort(c.begin(), c.end());
    int minCoin = INT_MAX;
    bool isPossible = false;
    for(int i=n-1; i>= 0; i--)
    {
        int ans = 0;
        int left = x;
        for(int j = i; j>= 0; j--)
        {
            if(left >= c[j]){
                ans += floor(left/c[j]);
                left = left%c[j];
                print<int>(ans, "ans");
                print<int>(left, "left");
            }
            print<int>(ans, "ans");
            print<int>(left, "left");
            if(left <= 0) break;
        }
        if(left == 0){
            minCoin = min(minCoin, ans);
            print<int>(minCoin, "minimum coin");
            isPossible = true;
        }
        print<int>(minCoin, "minimum coin");
    }
    cout << (isPossible ? minCoin: -1) << endl;
    return 0;
}