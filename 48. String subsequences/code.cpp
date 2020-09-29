/*
https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1
Expected Time Complexity: O(n*m)        [n and m are length of the strings]
Expected Auxiliary Space: O(n*m)
*/


#include<bits/stdc++.h>
using namespace std;

int dp[600][600];


int CountWays(string s, string t, int n, int m)
{
    if(m==0)
        return 1;
    if(n==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(s[n-1]==t[m-1])
     dp[n][m]=CountWays(s,t,n-1,m-1)+ CountWays(s,t,n-1,m);
     else 
     dp[n][m]=CountWays(s,t,n-1,m);
 
 return dp[n][m];
}
int main()
{
       string s,t;
       cin>>s>>t;
       int n=s.length();
       int m=t.length();
       memset(dp,-1,sizeof(dp));
       cout<<CountWays(s,t,n,m)<<endl;
}
