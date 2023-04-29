class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> decode_key;
        char value = 'a';
        string res = "";
        for(auto c: key){
            if( c==' ') continue;
            if(decode_key.find(c) == decode_key.end()){
                decode_key[c] = value;
                value++;
            }
        }
        for(auto c: message){
            if(c == ' '){
                res += " ";
            }else{
                res += decode_key[c];
            }
        }
        return res;
    }
};