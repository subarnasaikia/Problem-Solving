class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        if(n==2) return {0,1,1};
        if(n==3) return {0,1,1,2};
        int flag;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i<= n; i++){
            float j = log2(i);
            if(j - int(j) == 0){
                dp[i] = 1;
                flag = i;
            }else{
                dp[i] = 1 + dp[i-flag];
            }
        }
        return dp;
    }
};


// Best Solution

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        if(n == 0) return res;

        for(int i=1; i<=n; i++){
            if(i%2 == 0){
                res[i] = res[i/2];
            }else{
                res[i] = 1 + res[i/2];
            }
        }
        return res;
    }
};