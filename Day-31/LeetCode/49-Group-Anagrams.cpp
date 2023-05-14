auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagrams;
        for(auto str: strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            if(anagrams.count(temp))
            {
                anagrams.at(temp).push_back(str);
            }
            else
            {
                anagrams.emplace(temp, vector<string>());
                anagrams.at(temp).push_back(str);
            }
        }
        for( auto anagram: anagrams)
        {
            ans.push_back(anagram.second);
        }
        return ans;
    }
};