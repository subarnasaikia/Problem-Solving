#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin>>s;
    int size = s.size();
    map<char, int> mp;
    for(auto c: s)
    {
        mp[c]++;
    }
    string palindrom = "";
    int odd = -1;
    string oddChar = "";
    for(auto m: mp)
    {
        if(m.second&1)
        {
            if(odd != -1 || !(size&1))
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd = m.second;
            oddChar += m.first;
            int i =  (odd-1)/2;
            while(i--)
            {
                palindrom += m.first;
            }
        }else{
            int i = m.second/2;
            while(i--)
            {
                palindrom += m.first;
            }
        }
    }
    string temp = palindrom;
    reverse(palindrom.begin(), palindrom.end());
    cout << temp + oddChar + palindrom << endl;
    return 0;
}