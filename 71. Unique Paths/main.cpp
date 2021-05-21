class Solution {
    int dp[200][200];
public:
    
    int solve(int s,int e, int n, int m, vector<vector<int>> &grid){
          if(s==n-1 and e==m-1)return 1;
          if(dp[s][e]!=-1)return dp[s][e];
          int ans=0;
          if(e+1<m && grid[s][e+1]!=1)
               ans+=solve(s,e+1,n,m,grid);
        
          if(s+1<n && grid[s+1][e]!=1)
               ans+=solve(s+1,e,n,m,grid);
        return dp[s][e]=ans;
         
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          memset(dp,-1,sizeof(dp));
          int n=obstacleGrid.size(),m=obstacleGrid[0].size();
          if(obstacleGrid[0][0]==1)return 0;
          return solve(0,0,n,m,obstacleGrid);
    }
};
