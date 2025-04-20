//  1st Method

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> Running_Sum(nums.size());
        Running_Sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            Running_Sum[i] = Running_Sum[i-1] + nums[i]; 
        }
        return Running_Sum;
    }
};

// 2nd Method

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};