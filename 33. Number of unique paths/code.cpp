/*
https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0
*/


#include<bits/stdc++.h>
using namespace std;

int dp[50][50];

bool verify(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
        return true;
}


int  uniquePaths(int i , int j, int n, int m)
{
    if(i==n-1 && j==m-1)
        return 1;
    
    if(dp[i][j]!=0)
        return dp[i][j];

      if(verify(i,j+1,n,m))
        dp[i][j]=uniquePaths(i,j+1,n,m);

      if(verify(i+1,j,n,m))
        dp[i][j]+=uniquePaths(i+1,j,n,m);

        return dp[i][j];
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        memset(dp,0,sizeof(dp));
        cin>>n>>m;
       int temp= uniquePaths(0,0,n,m);
       if(n==1 && m==1)
       cout<<1<<endl;
       else
        cout<<dp[0][0]<<endl;
    }
}
