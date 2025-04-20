#include <bits/stdc++.h>
using namespace std;

int DIM = 8;
vector<vector<bool>> bloked(DIM, vector<bool>(DIM, false));
vector<bool> rowsTaken(DIM, false);
vector<bool> digonalTaken_1(DIM*2 - 1, false);
vector<bool> digonalTaken_2(DIM*2 -1 , false);
int valid_num = 0;

void search_queen(int c = 0)
{
    if(c == DIM)
    {
        valid_num++;
        return;
    }
    for(int i = 0; i< DIM; i++)
    {
        bool rowAvailable = !rowsTaken[i];
        bool digAvailable = !digonalTaken_1[c + i] && !digonalTaken_2[i - c + DIM - 1];
        if(!bloked[i][c] && rowAvailable && digAvailable)
        {
            rowsTaken[i] = digonalTaken_1[i + c] = digonalTaken_2[i - c + DIM - 1] = true;
            search_queen(c+1);
            rowsTaken[i] = digonalTaken_1[i + c] = digonalTaken_2[i - c + DIM - 1] = false;
        }
    }
}

int main()
{
    for(int i = 0; i< DIM; i++)
    {
        for(int j = 0; j<DIM; j++)
        {
            char rowState;
            cin >> rowState;
            bloked[i][j] = rowState == '*';
        }
    }
    search_queen();
    cout << valid_num << endl;
    return 0;
}