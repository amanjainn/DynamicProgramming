int dp[500][500];
  public:
/*You are required to complete this method*/
   int solve(string p,string s, int n, int m){
        
         if(m==0 && n==0)return 1;
         if(m==0 && p[n-1]=='*')return solve(p,s,n-1,m);
         if(n==0)return 0;
         if(m==0)return 0;
         if(dp[n][m]!=-1)return dp[n][m];
         int ans=0;
         if(p[n-1]==s[m-1] || p[n-1]=='?'){
             ans=solve(p,s,n-1,m-1);
         }else if(p[n-1]=='*'){
             ans=solve(p,s,n,m-1) || solve(p,s,n-1,m-1) || solve(p,s,n-1,m);
         }else{
             ans=0;
         }
        return dp[n][m]=ans; 
   }

    int wildCard(string pattern,string str)
    {
            memset(dp,-1,sizeof(dp));
            return solve(pattern, str, pattern.size(),str.size());
        
    }
