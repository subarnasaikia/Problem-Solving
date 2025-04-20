#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s; cin >> s;
        int ans = INT_MAX;
        vector<int> a(n);
        for(int i = 0; i<n-1; i++)
        {
            int cnt = 0;
            for(int j=0; j<n; j++)
            {
                if(i == j)
                {
                    a[cnt++] = 10*(s[j]- '0') + (s[j+1] - '0');
                    j++;
                }else {
                    a[cnt++] = (s[j] - '0');
                }
            }
            int val = 0;
            for(int k = 0; k<cnt; k++)
            {
                if(a[k] == 0){
                    val = -1;
                    break;
                }
                if(a[k] == 1) continue;
                val += a[k];
            }
            if(val == 0) val = 1;
            if(val == -1) val = 0;
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}