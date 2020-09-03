/*
Link :  https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
T: O(n^3)
S: O(n^2)

*/



#include<bits/stdc++.h>
using namespace std;

int dp[201][201];


int Mcm(int arr[],int i, int j){
    if(i==j)
        return 0;

     if(dp[i][j]!=-1)
        return dp[i][j];   

     int ans=INT_MAX;
     for(int k=i ; k<j ; k++){
         ans=min(Mcm(arr,i,k)+Mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j],ans);
     }            
     return  dp[i][j]=ans;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n ;i++)cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        cout<<Mcm(arr,1,n-1)<<endl;
    }
}
