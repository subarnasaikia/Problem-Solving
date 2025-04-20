#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++)
    {
        int val;
        cin >> val;
        a[val - 1] = i;
        b[i] = val - 1;
    }
    for(int i = 0; i<n; i++)
    {
        if(b[i] == n - 1) continue;
        if(a[b[i] + 1] < i) ans++;
    }
    cout << ans + 1 << endl;
}