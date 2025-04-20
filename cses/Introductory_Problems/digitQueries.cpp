#include <bits/stdc++.h>
using namespace std;

// 1 2  . . 0
//n n-1 . . 1
int main()
{
    int q;
    cin >> q;
    while(q--) // q times // overall timecomplexity will be O(qlogk)...
    {
        long long k;
        cin >> k; //  k = 19
        long long range = 9, initial_value = 1, digit = 1; //  digit = 1, 2, 3, 4 etc ..  
        // range for each digit -> d_1 = 1 to 9 , d_2 = 10 to 99  = 90 integer digit - > no of digit in the integer.
        // d_1 - > 1 , d_2 -> 10 .. 100 and so on...
        if(k <= range)
        {
            cout << k << endl;
            continue;
        }

        // 10 to 99 -> 90 integer and 180 digits will be present.
        // range = 9, 90, 900, so on...
        // time complexity for this while loop -> no of digit present in the value of the kth index.  O(digit) = O(logk)
        while(range * digit < k) // 9*1 < 19 // 90 * 2 = 180 /< 3
        {
            k -= (range * digit); // 19 - 9 = 10
            range *= 10; // 90
            initial_value *= 10; // 10
            digit++; // 2 counting the digit. 
        }
        // cout << "k " << k << endl;
        // cout << "digit " << digit << endl; 
        long long value = ((k-1) / (digit)) + initial_value; // 9 / 2 = 4 + 10 = 14 (this k is -> after reducting all integer that are less than the initial_value)
        // cout << "Value " << value <<endl;
        long long pos = digit - ((k-1) % (digit )); // 0 + 1 = 1 // 0 1 2 (digit -1 ),(digit )th ... 1  
        // cout << "IniPos " << pos << endl;
        // cout << "Pos " << pos << endl;
        long long ans = -1;
        // O(logk) or O(digit), O(log(value))
        while(pos--)
        {
            ans = value % 10;
            value /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}