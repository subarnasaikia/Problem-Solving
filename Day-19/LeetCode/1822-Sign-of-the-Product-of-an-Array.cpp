class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg_count = 0;
        for(auto n: nums)
        {
            if(n == 0) return 0;
            if(n < 0) neg_count++;
        }
        if(neg_count%2 == 0) return 1;
        return -1;
    }
};