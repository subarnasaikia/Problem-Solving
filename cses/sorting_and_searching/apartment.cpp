#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n>> m>>k;
    long long a[n], b[m];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    } 
    for(int i = 0; i<m; i++)
    {
        cin >> b[i];
    }
    sort(a, a+n), sort(b, b+m);
    int ans = 0;
    for(int i = 0, j = 0; i<m && j<n; )
    {
        if(b[i] <= a[j])
        {
            if(a[j] - b[i] <= k)
            {
                ans++;
                i++, j++;
            }else{
                i++;
            }
        }else{
            if(b[i] - a[j] <= k)
            {
                ans++;
                i++; j++;
            }else{
                j++;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}