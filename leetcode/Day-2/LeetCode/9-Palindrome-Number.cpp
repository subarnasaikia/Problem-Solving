#define ll long long

class Solution {
public:
    bool isPalindrome(int x) {
        ll temp = abs(x), newX = 0;
        while(temp != 0){
            newX =(newX* 10) +( temp%10);
            temp /= 10;
        }
        return (x == newX);
    }
};