// My first approach

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        int ans  = 0;
        while(num > 0)
        {
            digits.push_back(num%10);
            num /= 10;
        }
        for(int i = digits.size()-1; i>=0; i--){
            if(digits[i] == 6)
            {
                digits[i] = 9;
                break;
            }
        }
        for(int i=digits.size()-1; i>= 0; i--){
            ans = ans*10 + digits[i];
        }
        return ans;
    }
};

// Using String
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i=0; i<s.size(); i++){
            if(s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};