#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> circle;
    for(int i = 1; i<=n; i++) circle.push(i);
    bool remove = false;
    while(!circle.empty())
    {
        if(remove)
        {
            cout << circle.front() << " ";
            circle.pop();
            remove = false;
        }else {
            int top = circle.front();
            circle.pop();
            circle.push(top);
            remove = true;
        }
    }
    cout << endl;
    return 0;
}