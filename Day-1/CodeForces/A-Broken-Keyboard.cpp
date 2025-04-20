#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s ;
        set<char> res;
        cin >> s;
        int i = 0, j = 1;
        while( j <= s.size()){
            if(s[i] == s[j]){
                i += 2;
                j += 2;
            }else{
                res.insert(s[i]);
                i++;
                j++;
            }
        }
        // if(s[s.size() - 2] != s[s.size() - 1]) {res.insert(s[s.size() - 1]);}
        if(res.empty()){
            cout << endl;
        }else {
            for(auto it = res.begin(); it != res.end(); it++){
                cout << *it;
            }
            cout << endl;
        }
    }
    return 0;
}