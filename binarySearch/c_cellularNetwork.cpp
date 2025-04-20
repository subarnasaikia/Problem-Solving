#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> city_cords(n), tower_cords(m);
    for(ll& city_cord: city_cords)  cin >> city_cord;
    for(ll& tower_cord: tower_cords) cin >> tower_cord;
    sort(tower_cords.begin(), tower_cords.end());
    auto check = [&](int r) -> bool {
        for(const auto& city_cord: city_cords)
        {
            auto val = lower_bound(tower_cords.begin(), tower_cords.end(), city_cord - r);
            if(val == tower_cords.end()) return false;
            if(abs(city_cord - *val) > r) return false;
        }
        return true;
    };

    ll left = 0, right = 2*1e9 + 1;
    while(left <= right) {
        ll mid = left + (right - left)/2;
        if(check(mid)) right = mid - 1;
        else left = mid + 1;
    } 
    cout << left << endl;
    return 0;
}