#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	int five = 5;
	while(five <= n)
	{
		ans += n/five;
		five *= 5;
	}
	cout << ans << endl;
}
