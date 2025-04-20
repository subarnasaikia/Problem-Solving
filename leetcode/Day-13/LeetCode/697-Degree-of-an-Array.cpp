class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> umap;
        for( auto x: nums)
            umap[x]++;

        int max_count = 0;
        for(auto x: umap)
        {
            if(max_count < x.second)
            {
                max_count = x.second;
            }
        }
        if(max_count == 1){
            return 1;
        }
        vector<int> allWithMax;
        for(auto x: umap)
        {
            if(max_count == x.second)
            {
                allWithMax.push_back(x.first);
            }
        }

        int sml_lngth = INT_MAX; 
        for(auto res: allWithMax){
            int i = 0, count = 0, Max_count = max_count;
            while(Max_count > 0)
            {
                if(nums[i] != res && count == 0){
                    i++;
                }else if( nums[i] == res )
                {
                    count++;
                    Max_count--;
                    i++;
                }else{
                    count++;
                    i++;
                }
            }
            if(sml_lngth > count)
                sml_lngth = count;
        }
        return sml_lngth;
    }
};