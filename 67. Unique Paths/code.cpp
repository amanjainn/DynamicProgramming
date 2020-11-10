class Solution {
      int dp[101][101];
public:
      Solution()
      {
       memset(dp,-1,sizeof(dp));    
      }
      int uniquePathsHelper(int m, int n, int i, int j){
          if(i==m-1 && j==n-1)
          {
              return 1;
          }
          
          if(dp[i][j]!=-1)
          {
              return dp[i][j];
          }
          int result=0;
          if(j+1!=n)
          {
              result+=uniquePathsHelper(m,n,i,j+1);
          }
          if(i+1!=m)
          {
              result+=uniquePathsHelper(m,n,i+1,j);
          }
          return dp[i][j]=result;
          
          
      }
      int uniquePaths(int m, int n) {
           return uniquePathsHelper(m,n,0,0);   
      }
};
