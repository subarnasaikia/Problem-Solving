class Solution {
public:
    string sortSentence(string s) {
        string sentence[9];
        int i = 0;
        for(int j = 0; j<s.size(); j++){
            if(s[j] == ' '){
                sentence[s[j-1] - '0' - 1] = s.substr(i, (j-i-1));
                i = j+1;
            }
        }
        sentence[s[s.size()-1] - '0' - 1] = s.substr(i, (s.size()-i-1));
        string ans ="";
        ans += sentence[0];
        for(i = 1; i< 9; i++){
            if(sentence[i] != "")
                ans +=" "+ sentence[i];
        }
        return ans;
    }
};