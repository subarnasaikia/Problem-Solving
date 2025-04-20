class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> answers(nums.size(), 0);
        vector<int> leftsum(nums.size(), 0), rightsum(nums.size(), 0);
        int i = 1, j = nums.size() -2;
        while(i < nums.size())
        {
            leftsum[i] = leftsum[i-1] + nums[i-1];
            rightsum[j] = rightsum[j+1] + nums[j+1];
            i++;
            j--;
        }
        for(int i=0; i<nums.size(); i++)
        {
            answers[i] = abs(leftsum[i] - rightsum[i]);
        }
        return answers;
    }
};