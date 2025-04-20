#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin >> n;
    auto grayCode = [&](int g) -> string {
        int grayNumber = g ^ (g >> 1);
        string s(n, '0');
        int i = n - 1;
        while(i >= 0)
        {
            if(grayNumber & 1)
            {
                s[i] = '1';
            }
            grayNumber = grayNumber >> 1;
            i--;
        }
        return s;
    };

    for(int j = 0; j<(1 << n); j++)
    {
        cout << grayCode(j) << endl;
    }
    return 0;
}