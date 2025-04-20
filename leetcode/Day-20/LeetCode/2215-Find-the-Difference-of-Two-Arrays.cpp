class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        for(auto num: nums1){
            vector<int>::iterator it;
            it = find(nums2.begin(), nums2.end(),num);
            if(it == nums2.end()){
                it = find(answer[0].begin(), answer[0].end(),num);
                if(it == answer[0].end())
                    answer[0].push_back(num);
            }
        }
        for(auto num: nums2){
            vector<int>::iterator it;
            it = find(nums1.begin(), nums1.end(),num);
            if(it == nums1.end()){
                it = find(answer[1].begin(), answer[1].end(),num);
                if(it == answer[1].end())
                    answer[1].push_back(num);
            }
        }
        return answer;
    }
};