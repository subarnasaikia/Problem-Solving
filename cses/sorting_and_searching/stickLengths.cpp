#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    vector<int> p(n);
    for(auto &val : p) cin >> val;
    sort(p.begin(), p.end());
    int64_t ans1 = 0, ans2 = 0;
    int ind1 = (n/2), ind2 = (n -1)/2;
    for(auto val: p)
    {
        ans1 += abs(val - p[ind1]);
        ans2 += abs(val - p[ind2]);
    }
 
    cout << min(ans1, ans2)<< endl;
    
    return 0;
}
