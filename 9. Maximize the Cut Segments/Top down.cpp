/*
Link : https://practice.geeksforgeeks.org/problems/cutted-segments/0
*/


#include<bits/stdc++.h>
using namespace std;

int MaximumCuts(int dp[], int sizes[],int N){
    if(N==0)
        return 0;
    if(dp[N]!=0)
        return dp[N];

    int maxiCuts=INT_MIN;
    for(int i=0; i<3; i++){
         if(N-sizes[i]>=0){
             maxiCuts=max(maxiCuts,MaximumCuts(dp,sizes,N-sizes[i])+1);
         }
    }
    return dp[N]=maxiCuts;        
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int sizes[3];
        for(int i=0; i<3; i++)cin>>sizes[i];
        int dp[5000]={0};
        cout<<MaximumCuts(dp,sizes,n)<<endl;
    }
}
