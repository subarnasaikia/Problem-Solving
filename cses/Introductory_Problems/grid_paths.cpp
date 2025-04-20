#include <bits/stdc++.h>
using namespace std;

const int MAX_LENGTH = 48;
string PATH;
int path_dir[MAX_LENGTH];
const int DIM = 9;
// map<char, pair<int, int>> DIR;
int dir_x[4] = {1, -1, 0 , 0};
int dir_y[4] = {0, 0, 1, -1};

bool cur_path[DIM][DIM];

int valid_path = 0;
void search_path(int ind = 0, int cur_x  = 1, int cur_y = 1)
{

    // base condition for the recursive search_path
    if(cur_x  == 7 && cur_y == 1)
    {
        if(ind == MAX_LENGTH)
        {
            valid_path++;
            return ;
        }
        // pruning if distination (6, 0) reach before completing the path. PRUNING_1
        return ;
    }

    // Base condition if after all moves , we don't reach destination.
    if(ind == MAX_LENGTH)
    {
        return ;
    }

    // pruning -> if cur_path splits the grid in two half. PRUNING_2
    int left_x = cur_x, left_y = cur_y - 1, 
        right_x = cur_x , right_y = cur_y  + 1, 
        up_x = cur_x  + 1, up_y = cur_y, 
        down_x = cur_x - 1, down_y = cur_y;
    if(
        (!cur_path[left_x][left_y] && !cur_path[right_x][right_y] && cur_path[up_x][up_y] && cur_path[down_x][down_y]) || 
        (cur_path[left_x][left_y] && cur_path[right_x][right_y] && !cur_path[up_x][up_y] && !cur_path[down_x][down_y]) || 
        (cur_path[left_x][left_y] && cur_path[right_x][right_y] && cur_path[up_x][up_y] && cur_path[down_x][down_y])
    )
    {
        return;
    }

    if(path_dir[ind] < 4)
    {
        int new_x = cur_x + dir_x[path_dir[ind]];
        int new_y = cur_y + dir_y[path_dir[ind]];
        if(!cur_path[new_x][new_y])
        {
            cur_path[new_x][new_y] = true;
            search_path(ind+1, new_x, new_y);
            cur_path[new_x][new_y] = false;
        }
        return ;
    }

    for(int i = 0; i<4; i++)
    {
        int new_x = cur_x + dir_x[i];
        int new_y = cur_y + dir_y[i];
        if(!cur_path[new_x][new_y])
        {
            cur_path[new_x][new_y] = true;
            search_path(ind+1, new_x, new_y);
            cur_path[new_x][new_y] = false;
        }
    }
    return;
}

int main()
{
    cin >> PATH;
    int i = 0;
    for(auto p: PATH)
    {
        switch (p)
        {
        case 'D':
            path_dir[i] = 0;
            break;
        case 'U':
            path_dir[i] = 1;
            break;
        case 'R':
            path_dir[i] = 2;
            break;
        case 'L':
            path_dir[i] = 3;
            break;
        
        default:
            path_dir[i] = 4;
            break;
        }
        i++;
    }
    for(int i = 0; i<DIM; i++)
    {
        for(int j = 0; j<DIM; j++)
        {
            if(i == 0 || j == 0 || i == DIM - 1 || j == DIM - 1)
                cur_path[i][j] = true;
            else cur_path[i][j] = false;
        }
    }
    cur_path[1][1] = true;

    search_path();
    cout << valid_path << endl;
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<"secs"<<endl;
    return 0;
}
