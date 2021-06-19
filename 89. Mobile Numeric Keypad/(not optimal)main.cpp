  
class Solution{
  ll dp[30][11][11];
  vector<vector<char>> adj{{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
  ll dx[5]={0,-1,1,0,0};
  ll dy[5]={0,0,0,-1,1};
 
  public:
  bool check(int i , int j){
      if(i<0 || j<0 || i>=4 || j>=3 || adj[i][j]=='*' || adj[i][j]=='#')return false;
      return true;
  } 
  ll solve(int i, int j, int N){
     if(N==1)return 1;
     if(dp[N][i][j]!=-1)return dp[N][i][j];
     ll ans=0;
     for(int k=0; k<5 ;k++){
        int x=dx[k]+i,y=dy[k]+j;
        if(check(x,y)){
          ans+=solve(x,y,N-1);
        }
     }
     return dp[N][i][j]=ans;
  }

  long long getCount(int N)
  {
        memset(dp,-1,sizeof(dp));
        ll ans=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3 ;j++){
                 if(adj[i][j]=='*' || adj[i][j]=='#')continue;
                 ans+=(solve(i,j,N));
                
            }
        }
        return ans;
  }
}
