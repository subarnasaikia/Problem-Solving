#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n, x;
    cin >> n >> x;
    vector<int64_t> values(n);
    for(auto& val: values) cin >> val;
 
    map<int64_t, vector<pair<int, int >>> sumOfTwo;
    for(int i = 0; i<n; i++)
    {
        for(int j = i + 1; j<n; j++)
        {
            sumOfTwo[values[i] + values[j]].push_back(make_pair(i, j));
        }
    }
    for(auto sum: sumOfTwo)
    {
        int target = x  - sum.first;
        if(sumOfTwo.count(target))
        {
            for(auto idr: sum.second)
            {
                for(auto index: sumOfTwo[target])
                {
                    if(idr.first == index.first || idr.second == index.second || index.first == idr.second || idr.first == index.second) continue;
                    int ans[4] = {idr.first +1, idr.second + 1, index.first + 1, index.second + 1};
                    sort(ans, ans+4);
                    for(auto a: ans) cout << a << " ";
                    cout << "\n";
                    return 0;
                }
            }
            
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}