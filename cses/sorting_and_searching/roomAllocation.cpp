#include <bits/stdc++.h>
using namespace std;

class Compare
{
    public: 
        bool operator()( pair<int, int> below, pair<int, int> above)
        {
            if( below.first > above.first) return true;
            return false; 
        }
};

int main()
{
    int n;
    cin >> n;
    // for taking times in incresing order.
    multiset<pair<int, int>> times; 

    // for making maintaing the correct order of the input
    vector<vector<int>> input(n); 
    for(int i =0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        times.insert(make_pair(a, b));
        input[i].push_back(a);
        input[i].push_back(b);
    }

    // maintaing minHeap for finding the earliest deparature time with the room number
    priority_queue<pair<int,int>, vector<pair<int, int>>, Compare> deparatureTimes; 

    // for storing the room names for alloted times and to easily able to map and extract it for the output in order of the input
    map<int, map<int, queue<int>>> roomAlloted;

    int rooms = 1;
    while(!times.empty())
    {
        int at = times.begin()->first;
        int dt = times.begin()->second;
        // cout <<"times: " <<at << " " << dt << endl;
        if(deparatureTimes.empty())
        {
            // cout << "empty : " << dt << " " << rooms << endl;
            deparatureTimes.push(make_pair(dt, rooms));
            roomAlloted[at][dt].push(rooms);
        }else{
            int prevDt = deparatureTimes.top().first;
            int prevRoom = deparatureTimes.top().second;
            if(at <= prevDt)
            {
                rooms++;
                deparatureTimes.push(make_pair(dt, rooms));
                roomAlloted[at][dt].push(rooms);
                // cout << "at <= prevDt"<< at << " " << prevDt <<  "  " <<rooms << endl; 
            }else{
                // cout << "at > prevDt" << at << " " << prevDt << " " << prevRoom << endl;
                deparatureTimes.pop();
                deparatureTimes.push(make_pair(dt, prevRoom));
                roomAlloted[at][dt].push(prevRoom);
            }
        }
        times.erase(times.begin());
    }
    cout << rooms << endl;

    for_each_n(input.begin(), n, [&](vector<int> &arr)
    {
        cout << roomAlloted[arr[0]][arr[1]].front() << " ";
        roomAlloted[arr[0]][arr[1]].pop();
    });
    cout << endl;

    return 0;
}