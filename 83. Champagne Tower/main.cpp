class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
       double dp[305][305];
        for(int i=0; i<=100 ;i++)
            for(int j=0; j<=100 ;j++)
                dp[i][j]=0.0;
        
        dp[0][0]=poured*1.0;
        for(int i=0 ;i<=100 ;i++){
            for(int j=0; j<=i ;j++){
                double d=0.0;
                if(dp[i][j]>1.0){
                     d=dp[i][j]-1.0;
                     dp[i][j]=1.0;
                }
                dp[i+1][j]+=d/2.0;
                dp[i+1][j+1]+=d/2.0;
            }
        }
        return dp[query_row][query_glass];
    }
};
