#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n, x;
    cin >> n >> x;
    vector<pair<int64_t, int>> values;
    for(int i = 0; i<n; i++)
    {
        int a;
        cin >> a;
        values.push_back(make_pair(a, i));
    }
    sort(values.begin(), values.end());
    for(int i = 0; i<n; i++)
    {
        int l = 0, r = n-1;
        int64_t target = x - values[i].first;
        while(l < r)
        {
            if(i != l && i != r && (values[l].first + values[r].first == target))
            {
                int ans[3] = {values[i].second +1, values[l].second + 1, values[r].second +1};
                sort(ans, ans+3);
                for(auto a: ans) cout << a << " ";
                cout << endl;
                return 0;
            }else if((values[l].first + values[r].first > target)) r--;
            else l++;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}