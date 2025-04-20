#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<int> a(n), b(n); // a -> value to index mapping 
                            // b -> index to value mapping
    for(int i = 0; i<n; i++)
    {
        int val;
        cin >> val;
        a[val - 1] = i;
        b[i] = val - 1;
    }
    for(int i = 0; i<n; i++)
    {
        if(b[i] == n - 1) continue;
        if(a[b[i] + 1] < i) ans++;
    }
    ans++;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        if(x == y){
            cout << ans << endl;
            continue;
        }
        x--, y--;
        int X_value = b[x] ;
        int Y_value = b[y];
        bool X_pos = false, Y_pos = false;
        if(X_value != n-1 && a[X_value + 1] > x) X_pos =true;
        if(Y_value != n-1 && a[Y_value + 1] > y) Y_pos =true;

        b[x] = Y_value;
        b[y] = X_value;
        a[b[x]] = x;
        a[b[y]] = y;

        bool newX_pos = false, newY_pos = false;
        if(X_value != n-1 && a[X_value + 1] > y) newX_pos =true;
        if(Y_value != n-1 && a[Y_value + 1] > x) newY_pos =true;

        if(X_value < Y_value) swap(X_value, Y_value);

        if(X_pos && !newX_pos) ans++;
        else if(!X_pos && newX_pos) ans--;
        if(Y_pos && !newY_pos) ans++;
        else if( !Y_pos && newY_pos) ans--;

        cout << ans << endl;
    }
}