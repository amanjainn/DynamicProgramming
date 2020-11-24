const long MOD=1e9+7;
int dx[8]={-1,-1,1,1,2,2,-2,-2};
int dy[8]={-2,2,-2,2,-1,1,-1,1};
class Solution {
   int pad[4][3];
    int dp[10][10][5004];
public:
    Solution() {
        for(int i=0; i<3 ;i++){
            pad[0][i]=1+i;
            pad[1][i]=4+i;
            pad[2][i]=7+i;
        }
        pad[3][0]=pad[3][2]=-1;
        pad[3][1]=1;
        memset(dp,-1,sizeof(dp));
    }
    bool verify(int x, int y){
        if(x<0 || y<0 || x>3 || y>2 || pad[x][y]==-1)
            return false;
        return true;
    }
    long solve(int n, int curr, int x,int y){
            if(curr==0)
                return 1;
            long ans=0;
            if(dp[x][y][curr]!=-1)
                return dp[x][y][curr];
            for(int i=0; i<8 ; i++)
            {
                if(verify(x+dx[i],y+dy[i]))
                 ans+=(solve(n,curr-1,dx[i]+x,dy[i]+y)%MOD);
            }
        dp[x][y][curr]=ans%MOD;
        return dp[x][y][curr];
    }    
    int knightDialer(int n) {
        long ans=0;
        for(int i=0; i<4 ; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(pad[i][j]==-1)
                    continue;
                ans+=(solve(n,n-1,i,j))%MOD;
        
            }
        }
        return ans%MOD;
    }
};
