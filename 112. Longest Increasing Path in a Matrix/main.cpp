class Solution {
public:
    bool check(int x, int y, int n, int m){
        if(x<0 || y<0 ||x>=n || y>=m)return false;
        return true;
    }   
    int dfs(int i, int j,vector<vector<int>>&mat,vector<vector<int>> &dp){
           int dx[]={-1,1,0,0};
           int dy[]={0,0,-1,1};
           if(dp[i][j]!=-1)return dp[i][j];
           dp[i][j]=1;
           for(int k=0; k<4;  k++){
                int x=dx[k]+i,y=dy[k]+j;
                if(check(x,y,mat.size(),mat[0].size()) &&  mat[x][y]>mat[i][j]){
                    dp[i][j]=max(dp[i][j],1+dfs(x,y,mat,dp));
                }
           }
           return dp[i][j];          
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
          int n=matrix.size(),m=matrix[0].size();
          vector<vector<int>> dp (n,vector<int>(m,-1));
          int ans=0;
          for(int i=0 ;i<n ; i++){
              for(int j=0; j<m ; j++){
                   if(dp[i][j]==-1){
                       ans=max(ans,dfs(i,j,matrix,dp));
                   }
                   ans=max(ans,dp[i][j]);
              }
          }
         return ans;
    }
};
