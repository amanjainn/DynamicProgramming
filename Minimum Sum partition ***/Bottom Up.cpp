*/
Link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
T : O(n^2)
S : O(n^2)
*/


#include<bits/stdc++.h>
using namespace std;


void subsetSum(int arr[],bool dp[][50002],int n, int range){
     for(int i=1;i<=range; i++){
         dp[0][i]=false;
     }
     for(int i=0; i<=n ; i++){
         dp[i][0]=true;
     }
     for(int i=1; i<=n ;i++){
         for(int j=1; j<=range ;j++){
             if(arr[i-1]>j){
                 dp[i][j]=dp[i-1][j];
                 continue;
             }
             dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i-1]];
         }
     }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0; i<n ;i++)cin>>arr[i];
        int range=0;
        for(int i=0; i<n;i++)range+=arr[i];
        bool dp[100][50002];
        subsetSum(arr,dp,n,range);
        int minDiff=INT_MAX;
        for(int i=0 ; i<=range ;i++){
            if(dp[n][i]){
                int otherSum=range-i;
                 minDiff=min(minDiff,abs(i-otherSum));

            }
        }
        cout<<minDiff<<endl;
    
     }
}
