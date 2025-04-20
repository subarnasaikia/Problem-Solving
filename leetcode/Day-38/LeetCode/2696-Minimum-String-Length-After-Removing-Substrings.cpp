class Solution {
public:
    string remove( string s)
    {
        size_t i = s.find("CD");
        if(i != string:: npos)
        {
            s.erase(i , 2);
        }
        size_t j = s.find("AB");
        if(j != string:: npos)
        {
            s.erase(j , 2);
        }
        j = s.find("AB");
        
        i = s.find("CD");
        if(i != string::npos) return remove(s);
        if(j != string::npos) return remove(s);
        return s;
    }
    int minLength(string s) {
        string new_s = remove(s);
        return new_s.size();
    }
};