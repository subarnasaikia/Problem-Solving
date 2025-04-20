#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cubes(n);
    for(auto& cube: cubes) cin >> cube;

    multiset<int> stacks;
    for(auto cube: cubes)
    {
        if(stacks.empty())
        {
            stacks.insert(cube);
            continue;
        }
        auto it = stacks.upper_bound(cube);
        if(it == stacks.end())
        {
            stacks.insert(cube);
        }else{
            stacks.erase(it);
            stacks.insert(cube);
        }
    }
    cout << stacks.size() << endl;

    return 0;
}