/*
Link : https://practice.geeksforgeeks.org/problems/number-of-coins/0
Link : https://leetcode.com/problems/coin-change/

*/

#include<bits/stdc++.h>
using namespace std;

int dp[100006];

int minCoins(int coins[],int n, int sum){
         for(int i=1 ; i<=sum ; i++)
                 dp[i]=INT_MAX;
        dp[0]=0;
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=sum ;j++){
                if((j-coins[i-1])>=0){
                   if(dp[j-coins[i-1]]!=INT_MAX)
                    dp[j]=min(dp[j],dp[j-coins[i-1]]+1);
            }}
        }
        return (dp[sum]==INT_MAX?-1:dp[sum]);
}


int main(){
    int t;cin>>t;
    while(t--){
        int sum,n;
        cin>>sum>>n;
        int coins[n];
        for(int i=0; i<n ; i++){
            cin>>coins[i];
        }
        cout<<minCoins(coins,n,sum)<<endl;
    }
}
