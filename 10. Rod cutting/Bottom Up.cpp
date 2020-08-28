/*
Link : https://practice.geeksforgeeks.org/problems/rod-cutting/0
*/


#include<bits/stdc++.h>
using namespace std;

int maximumProfits(int sizes[],int profit[], int n){
        int dp[n+1][n+1];
        for(int i=1; i<=n ; i++)
            dp[0][i]=0;
        for(int i=0 ; i<=n ; i++)
            dp[i][0]=0;
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=n ; j++){
                if(sizes[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                    continue;
                }else{
                    dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i][j-sizes[i-1]]);
                }
            }
        } 
        return dp[n][n];       
}




int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       int sizes[n];
       for(int i=0; i<n ; i++)
            sizes[i]=i+1;
       int prices[n];
       for(int i=0; i<n; i++)
            cin>>prices[i];
        cout<<maximumProfits(sizes,prices,n)<<endl;
     }
}
