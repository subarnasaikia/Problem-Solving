#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    set<int> pairs;
    pairs.insert(0);
    pairs.insert(x);
    multiset<int> pair_lenghts;
    pair_lenghts.insert(x);
    // cout << pair_lenghts.size() << endl;
    for(int i = 0; i<n; i++)
    {
        int a;
        cin >> a;
        auto lowerItr = pairs.upper_bound(a);
        int next = *(lowerItr--);
        int prev = *(lowerItr);

        pairs.insert(a);
        pair_lenghts.erase(pair_lenghts.find(next - prev));
        pair_lenghts.insert((a - prev));
        pair_lenghts.insert((next - a));
        // cout << pair_lenghts.size() << " ";
        cout << *pair_lenghts.rbegin() << " ";
    }
    // for(auto p: pair_lenghts) cout << p << endl;
    cout << endl;
    return 0;
}