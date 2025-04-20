#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    map<int, vector<int>> integers;
    for(int i = 0; i<n; i++)
    {
        int a;
        cin >> a;
        integers[a].push_back(i+1);
    }
    bool pos = false;
    for(auto i: integers)
    {
        if(i.first >= x) continue;
        if(x == 2*i.first)
        {
            if(i.second.size() > 1)
            {
                int a = i.second[0], b = i.second[1];
                cout<< min(a, b) << " " << max(a, b) << endl;
                pos = true;
                break; 
            }else{
                continue;
            }
        }
        if(!integers.count(x - i.first)) continue;
        int a = i.second[0], b = integers[x - i.first][0];
        cout << min(a, b) << " " << max(a, b) << endl;
        pos = true;
        break;
    }
    if(!pos)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}