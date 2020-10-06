T:O(n^2)
S:O(n^2)


class Solution {
     int dp[1000][1000];
public:
    int editDistanceSolve(string s, string t,int n, int m)
	    {
	        if(n==0)
	        return m;
	        if(m==0)
	        return n;
	        
	        if(dp[n][m]!=0)
	        return dp[n][m];
	        
            if(s[n-1]!=t[m-1])
            {
                int ans1=editDistanceSolve(s,t,n-1,m)+1;
                int ans2=editDistanceSolve(s,t,n,m-1)+1;
                int ans3=editDistanceSolve(s,t,n-1,m-1)+1;
                dp[n][m]=min(ans1,min(ans2,ans3));
            }
            else 
            {
                dp[n][m]=editDistanceSolve(s,t,n-1,m-1);
            }
	        
	        return dp[n][m];
	    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        memset(dp,0,sizeof(dp));
        return editDistanceSolve(word1,word2,n,m);
    }
};
