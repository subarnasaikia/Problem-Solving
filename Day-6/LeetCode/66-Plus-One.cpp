// My first approach

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int i = digits.size()-1;
        while((digits[i] == 9) && (i >= 0)){
            if(i == 0){
                ans.emplace_back(0);
                ans.emplace_back(1);
                i--;
                break;
            }
            ans.push_back(0);
            i--;
        }
        if( i >= 0){
            int ele = digits[i] + 1;
            ans.emplace_back(ele);
            for(int j = i-1; j >= 0; j--){
                ans.emplace_back(digits[j]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Best solution

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int  i = digits.size() - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};