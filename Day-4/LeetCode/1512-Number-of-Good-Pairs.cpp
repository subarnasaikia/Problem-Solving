class Solution {
public:
    int sum(int n){
        return ((n-1)*n)/2;
    }
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans = 0;
        for(auto x: nums){
            umap[x]++;
        }
        for(auto x: umap ){
            ans += sum(x.second);
        }
        return ans;
    }
};