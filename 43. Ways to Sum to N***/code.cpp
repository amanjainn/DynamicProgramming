
/*
https://practice.geeksforgeeks.org/problems/ways-to-sum-to-n/0

*/



class Solution
{
  public:
   
    int countWays(int arr[], int m, int N) 
    { 
      long long mod=1000000007;
      int dp[N+1]={0};
      dp[0]=1;
      for(int j=1; j<=N ;j++)
      {
         for(int i=1; i<=m; i++)
         {
             if(j-arr[i-1]<0){
                 continue;
             }
             dp[j]=dp[j]%mod+dp[j-arr[i-1]]%mod;
             dp[j]=dp[j]%mod;
             
         }
      }

      return dp[N];
    } 
    
};
