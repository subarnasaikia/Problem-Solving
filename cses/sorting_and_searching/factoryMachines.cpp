#include<bits/stdc++.h>
using  namespace std;

int main()
{
    int64_t n, t;
    cin>>n>>t;
    vector<int64_t> k(n);
    for(int64_t& i: k) cin >> i;
    sort(k.begin(), k.end());
    auto check = [&](int64_t time) -> bool {
        int64_t product = 0;
        for(int64_t i = 0; i<n; i++)
        {
            product += (time / k[i]);
            if(product >= t)
            {
                return true;
            }
        }
        return false;
    };
    int64_t left = 1, right = k[0]*t;
    while(left <= right)
    {
        int64_t mid = left + (right - left) / 2;
        if(check(mid))
        {
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout << left << endl;
}