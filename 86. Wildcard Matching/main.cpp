class Solution {
public:
      int solve(string &p,string &s, int n, int m,vector<vector<int>>& dp){
          if(m==0 && n==0)return  dp[n][m]=1;
          if(m==0)
              return (p[n-1]=='*' && solve(p,s,n-1,m,dp));
         if(n==0)return 0; 
         if(dp[n][m]!=-1)return dp[n][m];
         int ans=0;
         if(p[n-1]==s[m-1] || p[n-1]=='?')
             ans=solve(p,s,n-1,m-1,dp);
         else if(p[n-1]=='*') ans=solve(p,s,n,m-1,dp) || solve(p,s,n-1,m,dp) || solve(p,s,n-1,m-1,dp);
         else  ans=0; 
         return dp[n][m]=ans; 
   }
    bool isMatch(string s, string p) {
       vector<vector<int>> dp(p.size()+1, vector<int>(s.size()+1, -1)); 
        return solve(p,s,p.size(),s.size(),dp);
    }
};
