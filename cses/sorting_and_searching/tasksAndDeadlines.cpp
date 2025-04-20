#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> durations;  
    for(int i = 0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        durations.push(make_pair(a, b));
    }
    int64_t reward = 0, startTime = 0;
    while(!durations.empty())
    {
        auto duration = durations.top().first;
        auto deadline = durations.top().second;
        startTime += duration;
        reward += deadline - startTime;
        durations.pop();
    }
    cout << reward << endl;
}