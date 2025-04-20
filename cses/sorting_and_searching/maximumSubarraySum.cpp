#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int64_t> x(n);
    for(auto &i: x) cin >> i;
    int64_t sum = 0, maxSum = INT64_MIN;
    for(auto i: x)
    {
        sum += i;
        maxSum = max(sum, maxSum);
        if(sum <= 0){
            sum = 0;
        }
    }
    cout << maxSum << endl;
    return 0;
}