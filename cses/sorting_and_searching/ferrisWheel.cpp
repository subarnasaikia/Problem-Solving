#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int weight[n];
    for(int i= 0; i<n; i++)
    {
        cin >> weight[i];
    }
    sort(weight, weight + n);
    int ans = 0;
    int i = 0, j = n-1;
    while(i <= j)
    {
        if(weight[i] + weight[j] <= x)
        {
            ans++;
            i++;
            j--;
        }else{
            ans++;
            j--;
        }
    }
    cout << ans << endl;
}