/*
https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one/0

*/


class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        int ans=0;
        int dp[N+1]={0};
        for(int i=0 ; i<N; i++)
        {
            dp[i]=1;
            for(int j=i-1; j>=0 ; j--)
            {
                if(A[j]!=A[i]+1  &&  A[j]!=A[i]-1)
                    continue;
                    
                dp[i]=max(dp[i],dp[j]+1);    
            }
        }
        for(int x : dp){
            ans=max(ans,x);
        }
        return ans;
    }
};
