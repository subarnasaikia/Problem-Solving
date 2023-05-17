class Solution {
public:
    int climbStairs(int n) {
      
      if(n == 1 ) return 1;
    
    //    int dp[n+1];
    //    dp[1] = 1;
    //    dp[2] = 2;
    int ekpiche = 2;
    int dopiche = 1;
       for(int  i =3;i<=n;i++)
       {
          int curr  = ekpiche + dopiche;
          dopiche = ekpiche;
          ekpiche = curr;        
      }

      return ekpiche;
    }

  
};