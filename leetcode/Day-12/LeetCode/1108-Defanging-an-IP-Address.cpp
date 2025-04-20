class Solution {
public:
    string defangIPaddr(string address) {
        char left = ']';
        char right = '[';
        for(int i=0; i<address.size(); i++)
        {
            if(address[i] == '.')
            {
                address.insert(address.begin() + (i+1),left);
                address.insert(address.begin() + i,right);
                i +=2;
            }
        }
        return address;
    }
};