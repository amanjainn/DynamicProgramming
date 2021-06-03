class Solution {
    double dp[200][50][50];
    public:
    bool valid(int r, int c, int n){
        if(r<0 ||r>=n || c<0 ||c>=n)return false;   
        return true;
    }
    double solve(int r, int c, int k, int n,int *dx, int *dy){
      if(!valid(r,c,n))return 0;
        if(k==0)return 1;
        if(dp[k][r][c]!=DBL_MAX)return dp[k][r][c];
        double prob=0.0;
        for(int i=0; i<8 ; i++){
            prob+=(double)solve(dx[i]+r,dy[i]+c,k-1,n,dx,dy)/8.0;
        }
        return dp[k][r][c]=prob;
    }
    double knightProbability(int N, int K, int r, int c) {
    int dx[]={-2,-2,-1,1,2,2,1,-1};
    int dy[]={-1,1,2,2,1,-1,-2,-2};
        for(int i=0; i<200; i++){
            for(int j=0; j<50 ;j++){
                for(int k=0; k<50 ;k++){
                    dp[i][j][k]=DBL_MAX;
                }
            }
        }
        return solve(r,c,K,N,dx,dy);    
    }
};
