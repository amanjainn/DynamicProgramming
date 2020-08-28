/*

Link : https://practice.geeksforgeeks.org/problems/coin-change/0
Leetcode : https://leetcode.com/problems/coin-change-2/
*/

#include<bits/stdc++.h>
using namespace std;

int NoofWays(int coins[],int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0; i<=sum ;i++){
         dp[0][i]=0;
    }
    for(int j=0 ; j<=n; j++){
        dp[j][0]=1;
    }
    for(int i=1; i<=n ; i++){
        for(int j=1 ;j<=sum ;j++){
            if(coins[i-1]>j){
                dp[i][j]=dp[i-1][j];
                continue;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[n][sum];
}



int main(){
    int t;
    cin>>t;
    while(t--){ 
        int n;cin>>n;
        int coins[n];
        for(int i=0 ; i<n ;i++)cin>>coins[i];
        int sum;cin>>sum;
        cout<<NoofWays(coins,n,sum)<<endl;
    }
}
