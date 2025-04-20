#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> value(n);
    for(auto& val: value) cin >> val;
    int64_t sum = 0;
    bool  done = false;
    sort(value.begin(), value.end());
    for(auto val: value)
    {
        if(sum + 1 >= val)
        {
            sum += val;
        }else{
            cout << sum + 1 << endl;
            done = true;
            break;
        }
    }
    if(!done) cout << sum +1 << endl;
    return 0;
}