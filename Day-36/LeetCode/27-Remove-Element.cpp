class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0 , j = 0;
        while ( j < nums.size())
        {
            if ( nums[i] != val )
            {
                i++;
                j++;
            }
            else if ( nums[j] == val )
            {
                j++;
            }
            else
            {
                nums[i] = nums[j];
                nums[j] = val;
                i++;
                j++;
            }
        }
        return i;
    }
};