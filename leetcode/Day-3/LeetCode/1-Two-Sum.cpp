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


// Another approch using Hash Table

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }

        return {-1, -1};
    }
};