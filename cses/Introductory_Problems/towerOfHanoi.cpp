#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves;

void towerOfHanoi(int n, int source, int aux, int dest)
{
    if(n == 0)
    {
        return ;
    }
    towerOfHanoi(n-1, source, dest, aux);
    moves.push_back(make_pair(source, dest));
    towerOfHanoi(n-1 , aux, source, dest); 
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 1, 2, 3);
    cout << moves.size() << endl;
    for(auto move: moves)
    {
        cout << move.first << " "  << move.second << endl;
    }
    return 0;
}