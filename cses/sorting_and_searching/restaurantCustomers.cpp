#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>,  greater<int>> inTime, outTime; // min heap
    for(int i=0; i<n; i++)
    {
        int in, out;
        cin >> in >> out;
        inTime.push(in), outTime.push(out);
    }
    int Maxcustomer = 0, in = inTime.top(), out = outTime.top(), curCostomer = 0;
    while(!inTime.empty() && !outTime.empty())
    {
        while (!inTime.empty() && in <= out)
        {
            curCostomer++;
            inTime.pop();
            in = inTime.top();
        }
        Maxcustomer = max(Maxcustomer, curCostomer);
        if(inTime.empty()) break;
        while(!outTime.empty() &&  out < in )
        {
            outTime.pop();
            out = outTime.top();
            curCostomer--;
        }
    }
    cout <<Maxcustomer << endl;

    return 0;
}