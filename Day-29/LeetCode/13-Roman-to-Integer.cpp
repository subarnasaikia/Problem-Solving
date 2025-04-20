class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_value = 
        {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };
        int numInINT = 0;
        int prev = 0;
        for ( int i = s.size() - 1; i >= 0; i--)
        {
            int temp = roman_value[s[i]];
            numInINT =  (temp < prev) ? (numInINT - temp) : (numInINT + temp);   
            prev = roman_value[s[i]];
        }
        return numInINT;
    }
};