#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int& i: a) cin >> i ;
        for(int& i: b) cin >> i ;
        int neg = 0, pos = 0, rateA = 0, rateB = 0;
        for(int i = 0; i<n; i++)
        {
            if(a[i] == b[i])
            {
                if(a[i] == -1)
                {
                    neg++;
                }
                if(a[i] == 1) pos++;
            }
            else if (a[i] == 1) rateA++;
            else if(b[i] == 1) rateB++;
        }
        if(pos == 0 && neg == 0)
        {
            cout << min(rateA, rateB) << endl;
            continue;
        }
        if(rateA < rateB)
        {
            int rem = min(rateB-rateA, pos);
            rateA += rem;
            pos -= rem;
        }
        if(rateA > rateB)
        {
            int rem  = min(rateA - rateB, pos);
            rateB += rem;
            pos -= rem;
        }
        if(rateA == rateB)
        {
            rateA += (pos/2);
            rateB += (pos - pos/2);
        }
        int rem = min(abs(rateA - rateB), neg);
        if(rateA < rateB)
        {
            rateB -= rem;
        }else if(rateA > rateB)
        {
            rateA -= rem;
        }
        neg -= rem;
        rateA -= (neg/2);
        rateB -=(neg - neg/2);
        cout << min(rateA, rateB) << endl;
    }

    return 0;
}