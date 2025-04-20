// O(n^2) solution

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(int i= 0; i<nums.size(); i++){
            int  count = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] < nums[i]) count++;
            }
            ans.emplace_back(count);
        }
        return ans;
    }
};

