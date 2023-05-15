class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_product;
        vector<int> sufix_product(nums.size() , 1);
        vector<int> ans;
        prefix_product.push_back(1);
        // sufix_product.push_back(1);
        for(int i = 1; i < nums.size(); i++)
        {
            prefix_product.push_back((prefix_product[i-1] * nums[i-1]));
        }
        for(int i =nums.size() - 2; i >= 0; i--)
        {
            sufix_product[i] = (sufix_product[i+1] * nums[i+1]);
        }
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back(prefix_product[i] * sufix_product[i]);
        }
        return ans;
    }
};

// 1 , 1, 2, 6
// 24 , 12, 4, 1
// 24 , 12 , 8 , 6

// 1 , -1 , -1 , 0 , 0
// 0 , 0 , -9 , 3, 1
// 0 , 0 , 9, 0 , 0