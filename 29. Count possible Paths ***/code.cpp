/*
https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right/0
*/


#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
bool verify(int i, int j, int n, int m)
{
    if(i<0 || j<0 || i>=n ||  j>=m)
        return false;
        return true;
}

int dp[200][200];

int countPaths(int i, int j, int n, int m)
{
    if(i==n-1 && j==m-1)
        return 1;
     if(dp[i][j]!=0)
        return dp[i][j];
     if(verify(i,j+1,n,m))
        dp[i][j]+=countPaths(i,j+1,n,m)%mod;
     if(verify(i+1,j,n,m))
        dp[i][j]+=countPaths(i+1,j,n,m)%mod;

        return dp[i][j]%mod;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        cout<<countPaths(0,0,n,m)<<endl;
    }
}
