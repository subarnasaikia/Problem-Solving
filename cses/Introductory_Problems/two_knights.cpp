#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++)
    {
        long long all_possible_ways = 1ll*(i*i)*(i*i - 1)/2; // nCr
        long long restricted_ways = 1ll*4*(i-1)*(i-2); // there are 2 restricted ways in 2*3 grid -> there are (i-1)(i-2) ways to find for each horizontally and vertically.
        cout << all_possible_ways - restricted_ways << endl;
    }
}