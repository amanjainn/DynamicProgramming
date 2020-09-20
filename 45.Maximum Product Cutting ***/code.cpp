/*
https://practice.geeksforgeeks.org/problems/maximum-product-cutting/0
*/



#include<bits/stdc++.h>
using namespace std;


long long dp[1005];

long long  productCutting(int n)
{
    if(n==1)
        return 1;
     if(dp[n]!=-1)
        return dp[n];
        long long ans=0;
        for(int i=1  ;i<n ; i++){
            ans=max(ans,max(i*productCutting(n-i),(long long)(n-i)*i));
        }
        return dp[n]=ans;

}
int main()
{
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<productCutting(n)<<endl;
}
