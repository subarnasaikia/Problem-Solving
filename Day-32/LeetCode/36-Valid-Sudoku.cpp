class Solution {
public:
    bool helper(vector<vector<char>>& board,char val,int r,int c){
        for(int i=0;i<9;i++){
            if(board[r][i]==val && i!=c){
                return false;
            }
            if(board[i][c]==val && i!=r){
                return false;
            }
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==val &&r!=(3*(r/3)+i/3) && (3*(c/3)+i%3)!=c)return false;
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    bool val=helper(board,board[i][j],i,j);
                    if(val==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};