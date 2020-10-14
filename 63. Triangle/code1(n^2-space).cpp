class Solution {
    int dp[500][500];
public:
      
        int minimumTotalHelper(vector<vector<int>>&triangle,int i, int j, int n)
        {
                if(i==n-1)
                    return triangle[i][j];
                
                if(dp[i][j]!=0)
                    return dp[i][j];
            
            dp[i][j]=min(minimumTotalHelper(triangle,i+1,j,n),minimumTotalHelper(triangle,i+1,j+1,n))+triangle[i][j];
            return dp[i][j];
            
        }
    int minimumTotal(vector<vector<int>>& triangle) {
          int n=triangle.size();
          memset(dp,0,sizeof(dp));
          return minimumTotalHelper(triangle,0,0,n);
        
    }
};
