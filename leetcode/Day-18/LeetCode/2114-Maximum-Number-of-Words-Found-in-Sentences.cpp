class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_words = 0; 
        for(auto s: sentences){
            int words = 1;
            for(auto c: s){
                if(c == ' ') words++;
            }
            max_words = max(max_words, words);
        }
        return max_words;
    }
    
};