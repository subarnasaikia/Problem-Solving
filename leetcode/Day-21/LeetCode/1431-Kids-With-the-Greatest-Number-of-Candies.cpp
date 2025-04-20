class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> results;
        int greatest = *max_element(candies.begin(), candies.end());
        for(auto candy: candies)
        {
            if((candy + extraCandies) >= greatest)
                results.push_back(true);
            else
                results.push_back(false);
        }
        return results;
    }
};