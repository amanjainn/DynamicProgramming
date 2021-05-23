class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        vector<vector<int>>dp (n,vector<int>(n,-1));
        for(int gap =0; gap <n  ;gap++){
            for(int start=0,j=gap ;j<n ; start++,j++){
                  if(gap==0){
                    dp[start][j]=1;
                  }else if(gap==1){
                        dp[start][j]=(s[start]==s[j]);
                  }else{
                       dp[start][j]= (s[start]==s[j] && (dp[start+1][j-1]==1));
                  }
                if(dp[start][j]==1)ans++;       
            }
        }  
        return ans;
    }
};
