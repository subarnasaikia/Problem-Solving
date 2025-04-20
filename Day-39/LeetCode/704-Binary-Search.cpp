class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        // mid = (left + right)/2;
        while (left <= right)
        {
            mid = (left + right)/2;
            if(nums[mid] == target)
            {
                return mid;
            }else if (nums[mid] < target)
            {
                left = mid +1;
            }else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};