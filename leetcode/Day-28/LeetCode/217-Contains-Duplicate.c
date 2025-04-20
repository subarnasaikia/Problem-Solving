auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> unique;
        for(auto i: nums)
        {
            unique[i]++;
            if(unique[i] > 1) return true;
        }
        return false;
    }
};