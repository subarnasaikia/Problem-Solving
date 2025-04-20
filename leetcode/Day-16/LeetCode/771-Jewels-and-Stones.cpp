// O(m*n) 

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_map<char, int> uni_jewels, uni_stones;
        for(char s: jewels) uni_jewels[s]++;
        for(char s: stones) uni_stones[s]++;

        for(auto x: uni_jewels){
            if(uni_stones.find(x.first) != uni_stones.end()){
                ans += uni_stones[x.first];
            }
        }
        return ans;
    }
};


// O(n) where n = max(jewels.size(), stones.size())

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_map<char, int> uni_jewels, uni_stones;
        for(char s: jewels) uni_jewels[s]++;
        for(char s: stones) uni_stones[s]++;

        for(auto x: uni_jewels){
            ans += uni_stones[x.first];
        }
        return ans;
    }
};




// O(n) where n = max(jewels.size(), stones.size())

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_map<char, int> uni_stones;
        
        for(char s: stones) uni_stones[s]++;
        for(char s: jewels) ans += uni_stones[s];
        return ans;
    }
};