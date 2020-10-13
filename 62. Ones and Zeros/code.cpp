class Solution {
    int dp[606][105][105];
public:
    int findMaxHelper(vector<string> &strs, int i, int m , int n){
           if(i==0 || (m==0 && n==0))
               return 0;
            if(dp[i][m][n]!=-1)
                return dp[i][m][n];
           int count0=count(strs[i-1].begin(),strs[i-1].end(),'0');
           int count1=count(strs[i-1].begin(),strs[i-1].end(),'1');
           if(m>=count0 && n>=count1)
           {
               int op1=findMaxHelper(strs,i-1,m-count0,n-count1)+1;
               int op2=findMaxHelper(strs,i-1,m,n);
               dp[i][m][n]=max(op1,op2);
           }
           else 
           {
                 dp[i][m][n]= findMaxHelper(strs,i-1,m,n);
           }
        return dp[i][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
          int i=strs.size();
          memset(dp,-1,sizeof(dp));
          return findMaxHelper(strs,i,m,n);
    }
};
