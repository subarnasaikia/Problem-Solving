class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.emplace_back(nums[i]);
            ans.emplace_back(nums[i + n]);
        }
        return ans;
    }
};