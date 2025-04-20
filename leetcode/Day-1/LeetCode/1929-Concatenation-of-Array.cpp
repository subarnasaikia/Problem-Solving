class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(2 * size);
        for(int i = 0; i < size; i++)
        {
            ans[i] = nums[i];
            ans[i + size] = nums[i];
        }
        return ans;
    }
};