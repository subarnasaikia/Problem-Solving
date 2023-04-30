class Solution {
public:
    string removeDigit(string number, char digit) {
        int freq = 0;
        for(auto c: number){
            if(c == digit) {
                freq++;
                if(freq > 1) break;
            }
        }
        
        if(freq == 1){
            int i = 0;
            for(auto c: number){
                if(c == digit){
                    number.erase(number.begin() + i);
                    return number; 
                }
                i++;     
            }
        }
        int lastIdx = 0;
        for(int i = 0; i < number.size() - 1; i++){
            if(number[i] == digit && digit < number[i+1]){
                number.erase(number.begin() + i);
                return number; 
            }
            if(number[i] == digit){
                lastIdx = i;
            }
        }
        if(number[number.size()-1] == digit){
            number.erase(number.begin() + (number.size() - 1 ));
            return number;
        }else{
            number.erase(number.begin() + lastIdx);
            return number; 
        }
        return "";
    }
};