#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
	ll testCases;
	cin >> testCases;
	while(testCases--)
	{
		ll n, k, f;
		cin >> n >> f >> k;
		ll a[n];
		for(int i=0; i<n; i++) cin >> a[i];
		int favoriteValue = a[f-1];
		sort(a, a+n, greater<int>());
		if(a[k-1] < favoriteValue || (k ==n || a[k] < favoriteValue))
			cout << "YES\n";
		else if(a[k-1] > favoriteValue)
			cout << "NO\n";
		else cout << "MAYBE\n";
	}
	return 0;
}
