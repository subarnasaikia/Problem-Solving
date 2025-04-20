#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin >> n;
    vector<int> a(n);
    for(auto&i: a) cin >> i;
    map<int, queue<int>> index;
    for(int i = 0; i<n; i++)
    {
        index[a[i]].push(i);
    }
    set<int> prev;
    int i = 0, cur_ptr = 0, max_lenght = 0;
    while(i < n)
    {
        if(!prev.empty() && prev.count(a[i]))
        {
            auto &findInd = index[a[i]];
            int curInd = findInd.front();
            while(curInd < cur_ptr)
            {
                findInd.pop();
                curInd = findInd.front();
            }
            if(curInd != i)
            {
                int lenght = i - cur_ptr;
                max_lenght = max(max_lenght, lenght);
                cur_ptr = curInd + 1;
                findInd.pop();
            }
        }
        else{
            prev.insert(a[i]);
        }
        i++;
    }
    cout << max(max_lenght, i - cur_ptr) << endl;
    return 0;
}