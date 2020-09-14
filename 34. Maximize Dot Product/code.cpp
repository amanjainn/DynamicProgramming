/*
Link : https://practice.geeksforgeeks.org/problems/maximize-dot-product/0

*/


#include <bits/stdc++.h>
using namespace std;

int dp[2000][2000];
int maxDotProduct(int n, int m, int a[], int b[]) 
{ 
		if(n==0 || m==0 )
            return 0;
        if(dp[n][m]!=0)
            return dp[n][m];
        dp[n][m]=max(a[n-1]*b[m-1]+maxDotProduct(n-1,m-1,a,b),maxDotProduct(n-1,m,a,b));
        dp[n][m]=max(dp[n][m],maxDotProduct(n,m-1,a,b));
        return dp[n][m];    
} 

int main() 
{
    int n,m;cin>>n>>m;
    int a[n],b[n];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n ; i++)cin>>a[i];
    for(int j=0 ; j<m ; j++)cin>>b[j];
    cout<<maxDotProduct(n,m,a,b)<<endl;

}
