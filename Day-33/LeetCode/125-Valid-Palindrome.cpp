class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin() , s.end() , s.begin() , ::tolower);
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
            {
                if((s[j] >= 97 && s[j] <= 122) || (s[j] >= 48 && s[j] <= 57))
                {
                    if(s[i] == s[j])
                    {
                        i++;
                        j--;
                    }
                    else return false;
                }
                else 
                {
                    j--;
                }
            }
            else 
            {
                i++;
            }
        }
        return true;
    }
};