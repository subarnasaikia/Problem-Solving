class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        for(auto x: accounts){
            int sum = 0;
            for(auto y: x){
                sum += y;
            }
            richest = max(richest, sum);
        }
        return richest;
    }
};