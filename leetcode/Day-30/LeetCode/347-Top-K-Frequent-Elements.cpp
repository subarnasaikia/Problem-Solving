class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> vpair;
        vector<int> ans;
        for(int i: nums)
        {
            freq[i]++;
        }
        for(auto i: freq)
        {
           vpair.push_back(make_pair(i.second, i.first));
        }
        sort(vpair.begin(), vpair.end(), greater<>());
        for(auto i: vpair)
        {
            if(k > 0)
            {
                ans.push_back(i.second);
                k--;
            }else return ans;
        }
        return ans;
    }
};