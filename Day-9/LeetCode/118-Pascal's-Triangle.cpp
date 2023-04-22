class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        pascal[0].push_back(1);
        if(numRows == 1) return pascal;
        pascal[1].push_back(1);
        pascal[1].push_back(1);
        if(numRows == 2) return pascal;

        for(int i=2; i<numRows; i++){
            pascal[i].push_back(1);
            for(int j = 0; j<i-1; j++){
                pascal[i].push_back((pascal[i-1][j] + pascal[i-1][j+1]));
            }
            pascal[i].push_back(1);
        }

        return pascal;
        
    }
};

// Another short code

class Solution {
public:
    vector<vector<int>>generate(int numRows) {
        vector<vector<int>>result(numRows);
        for(int i=0; i<numRows; i++){
            result[i].resize(i+1, 1);
            for(int j=1; j<i; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};