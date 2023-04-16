class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int, int>> vpair;
        vector<int> ans;
        for(int i = 0; i< nums.size(); i++){
            vpair.push_back(make_pair(nums[i], i));
        }
        sort(vpair.begin(), vpair.end());
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(vpair[i].first + vpair[j].first == target){
                ans.push_back(vpair[i].second );
                ans.push_back(vpair[j].second );
                break;
            }else if(vpair[i].first + vpair[j].first > target){
                j--;
            }else{
                i++;
            }
        }
        return ans ;
    }
};