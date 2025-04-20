#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> times(n);
    for(int& i: times) cin >> i;
    int64_t max_ele_double =( *max_element(times.begin(), times.end())) * 2 * 1ll;
    int64_t sum = accumulate(times.begin(), times.end(), 0ll);
    cout << max(sum,max_ele_double) << endl;
    return 0;
}