#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    ordered_set<int> os;
    for(int i = 1; i<= n; i++)
    {
        os.insert(i);
    }
    int i = 0;
    while(!os.empty())
    {
        i = (i + k) % os.size();
        auto itr = os.find_by_order(i);
        cout << *itr << " ";
        os.erase(itr);
    }
    cout << endl;
    return 0;
}