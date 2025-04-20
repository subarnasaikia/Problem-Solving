#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
	 	cin >> n >> m;
		string a;
		cin >> a;
		map<char, int> mp;
		string p = "ABCDEFG";
		for(auto &c : a)
		{
			mp[c]++;
		}
		int ans = 0;
		for(auto &pi : p)
		{
			if(mp.count(pi))
			{
				ans += (m - min(mp[pi],m)); 
			}else ans += m;
		}		
		cout << ans << endl;
	}
	return 0;
}
