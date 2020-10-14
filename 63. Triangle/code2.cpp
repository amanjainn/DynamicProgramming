class Solution {
public:
      
    int minimumTotal(vector<vector<int>>& triangle) {
          int n=triangle.size();
          int dp[n+1];
          memset(dp,0,sizeof(dp));
          for(int i=n ; i>0 ;i--)
          {
              for(int j=1; j<=i ;j++)
              {
                     if(i==n)
                         dp[j]=triangle[i-1][j-1];
                      else 
                          dp[j]=min(dp[j],dp[j+1])+triangle[i-1][j-1];
              }
          }
        return dp[1];
        
    }
};
