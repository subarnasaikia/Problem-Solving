class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, ele = nums[0];
        for(int j = 1; j<nums.size(); j++)
        {
            if(ele != nums[j]){
                nums[i] = nums[j];
                ele = nums[j];
                i++;
            }
        }
        nums.resize(i);
        return i;
    }
};