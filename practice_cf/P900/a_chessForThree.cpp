#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int p[3];
		int ans = -1;
		cin >> p[0] >> p[1]>> p[2];
		if ((p[0] + p[1]+p[2])%2 != 0) 
		{
			cout << ans << endl;
			continue;
		}
		for(int i = 0; i<=p[0]; i++)
		{
			for(int j = 0; j<= p[0]; j++){
				for(int k=0; k<=p[1]; k++)
				{
					if( (p[0]- i - j)%2 != 0 || p[0] < (i+j)) continue;
					if( (p[1] - i - k)%2 != 0 || p[1] < (i+k)) continue;
					if( (p[2] - j - k)%2 != 0 || p[2] < (j + k)) continue;
					ans = max(ans, i + j + k);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
