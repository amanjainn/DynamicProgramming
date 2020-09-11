/*
Link : https://practice.geeksforgeeks.org/problems/find-optimum-operation/0
*/

#include<bits/stdc++.h>
using namespace std;


int dp[10000];

int minOperations(int n,int p){
    if(p==n)
        return 0;
    if(dp[p]!=-1)
        return dp[p];

    int ans=INT_MAX;
    if(p!=0 && p*2<=n)
    ans=min(ans,minOperations(n,p*2)+1);
    ans=min(ans,minOperations(n,p+1)+1);
    return dp[p]=ans; 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        cout<<minOperations(n,0)<<endl;
    }
}
