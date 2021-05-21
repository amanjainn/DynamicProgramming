class Solution {
    int dp[101][101];
    public:
    int solve(string s1,string s2 ,int i, int j, string s3){
      if(i==s1.size() and j==s2.size())return 1;
      if(dp[i][j]!=-1)return dp[i][j];
      int k=i+j;
      int ans1=0,ans2=0;
      if(i<s1.size() && s1[i]==s3[k]) ans1=solve(s1,s2,i+1,j,s3);
      if(j<s2.size() && s2[j]==s3[k]) ans2=solve(s1,s2,i,j+1,s3);
      return dp[i][j]=ans1 || ans2;
    }
    bool isInterleave(string s1, string s2, string s3) {
            memset(dp,-1,sizeof(dp));
            if(s3.size()==0)return true;
            if(s1.size()+s2.size()!=s3.size())return false;
           return solve(s1,s2,0,0,s3);
    }
};
