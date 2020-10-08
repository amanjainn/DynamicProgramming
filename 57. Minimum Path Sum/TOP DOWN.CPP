https://leetcode.com/problems/minimum-path-sum/submissions/


class Solution {
     int dp[1005][1005];
public:
    
    int minPathSumHelper(vector<vector<int>>&grid,int i, int j, int n, int m)
     {
            if(i>=n || j>=m)
                return 32000; //ANY MAX NUMBER
           
            if(i==n-1 && j==m-1)
                return grid[i][j];
            
            if(dp[i][j]!=-1)
                return dp[i][j];
        
             dp[i][j]=min(minPathSumHelper(grid,i+1,j,n,m)+grid[i][j],minPathSumHelper(grid,i,j+1,n,m)+grid[i][j]);
             return dp[i][j];
             
     }
    

    int minPathSum(vector<vector<int>>& grid) {
            memset(dp,-1,sizeof(dp));
            int n=grid.size();
            int m=grid[0].size();
            return minPathSumHelper(grid,0,0,n,m);
    }
};
