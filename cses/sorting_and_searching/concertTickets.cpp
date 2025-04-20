#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    vector<int> t(m);
    for(int i = 0; i< n; i++)
    {
        int v; cin >> v;
        h.insert(v);
    }
    for(auto &v: t)
    {
        cin >> v;
    }

    auto binarySearch = [&](int val) -> int 
    {
        auto itr = h.upper_bound(val);
        if(itr == h.begin())
        {
            return -1;
        }else{
            int v = *(--itr);
            h.erase(itr);
            return v;
        }
    };

    for(auto v: t)
    {
        cout << binarySearch(v) << endl;
    }

    return 0;
}