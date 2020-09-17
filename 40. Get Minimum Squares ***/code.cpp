/*
https://practice.geeksforgeeks.org/problems/get-minimum-squares/0
*/

#include<bits/stdc++.h>
using namespace std;


int dp[100005];


int getMinSquares(int n)
{
    if(n==0)
    return 0;
    if(dp[n]!=-1)
        return dp[n];
    int p=sqrt(n);
    int ans=INT_MAX;
    for(int i=p ; i>=1; i--){
        if(i*i<=n){
            ans=min(ans,getMinSquares(n-i*i)+1);
        }
    }
    return dp[n]=ans;
}


int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<getMinSquares(n)<<endl;
    
}
