#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 4 == 0)
    {
        cout << "YES\n";
        cout << 2* n/4 << endl;
        int temp = n;
        while(temp > 0)
        {
            cout << temp << " " << temp - 3 << " ";
            temp -=4;
        }
        cout << endl;
        cout << 2* n/4 << endl;
        temp = n-1;
        while(temp > 0)
        {
            cout << temp << " " << temp - 1 << " ";
            temp -=4;
        }
        cout << endl;
        return 0;
    }
    if((n-3)%4 == 0)
    {
        cout << "YES\n";
        cout << 2*((n-3)/4) + 1 << endl;
        int temp = n;
        while(temp > 3)
        {
            cout << temp << " " << temp - 3 << " ";
            temp -=4;
        }
        cout << 3 << endl;
        cout << 2*((n-3)/4) + 2 << endl;
        temp = n-1;
        while(temp > 3)
        {
            cout << temp << " " << temp -1 << " ";
            temp -=4;
        }
        cout << "2 1\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}