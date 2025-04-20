#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(auto &val: arr) cin >> val;
    int i = 0, j = 0;
    int64_t sum  = 0, cnt = 0;
    while(i < n && j < n)
    {
        while(j < n && sum < x)
        {
            sum += arr[j];
            j++;
        }
        if(sum == x) {cnt++;
            sum -= arr[i];
            i++;
            continue;
        }
        while(i < n && sum > x)
        {
            sum -= arr[i];
            i++;
        }
    }
    if(sum == x) cnt++;
    cout << cnt << endl;
    return 0;
}