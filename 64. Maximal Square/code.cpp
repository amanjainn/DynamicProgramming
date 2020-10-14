class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
          int n=matrix.size();
          if(n==0)return 0;
          int m=matrix[0].size();
          int dp[n+1][m+1];
          memset(dp,0,sizeof(dp));
          int largest=0;
          for(int i=1; i<=n ; i++)
          {
              for(int j=1;j<=m ;j++)
              {
                   if(matrix[i-1][j-1]=='1')
                   {
                       dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                     
                   }
                largest=max(dp[i][j],largest);        
              }
          }
        return largest*largest;
           
    }
};
