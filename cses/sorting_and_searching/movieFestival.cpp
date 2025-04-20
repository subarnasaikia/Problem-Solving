#include <bits/stdc++.h>
using namespace std;

class Compare
{
    public: 
        bool operator()( pair<int, int> below, pair<int, int> above)
        {
            if( below.second > above.second) return true;
            else if(below.second == above.second && below.first > above.first) return true;
            return false; // sorting the endTime in ascending order if the endtime same sort with start time ascending order.
        }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> startAndEndTime;
    for(int i = 0; i< n; i++)
    {
        int a, b;
        cin >> a >> b;
        startAndEndTime.push(make_pair(a, b));
    }
    int endTime = startAndEndTime.top().second, ans = 1;
    startAndEndTime.pop();
    while(!startAndEndTime.empty())
    {
        auto movieTime = startAndEndTime.top();
        int startTime = movieTime.first;
        while(!startAndEndTime.empty() && startTime < endTime)
        {
            startAndEndTime.pop();
            startTime = startAndEndTime.top().first;
        }
        if(startAndEndTime.empty()) break;
        ans++;
        endTime = startAndEndTime.top().second;
        startAndEndTime.pop();
    }
    cout << ans << endl;
    return  0;
}