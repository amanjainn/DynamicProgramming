/*
Link: https://practice.geeksforgeeks.org/problems/count-number-of-hops/0

*/


#include<bits/stdc++.h>
using namespace std;

int dp[100];

int countHops(int n){
    if(n<0)
        return 0;
    if(n==1|| n==0)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    dp[n]=countHops(n-1)+countHops(n-2)+countHops(n-3);
    return dp[n];        
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));
        cout<<countHops(n)<<endl;
    }
}
