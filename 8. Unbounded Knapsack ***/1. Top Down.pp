/*
T: O(n^2)
S: O(n^2)
*/


#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int UnboundedKnapsack(int val[],int wt[],int n, int w){
     if(w==0 || n==0)
        return 0;

      if(dp[n][w]!=-1)
            return  dp[n][w];

      if(wt[n-1]<=w){
          return dp[n][w]=max(UnboundedKnapsack(val,wt,n-1,w),val[n-1]+UnboundedKnapsack(val,wt,n,w-wt[n-1]));
       }
      return dp[n][w]=UnboundedKnapsack(val,wt,n-1,w);      
    
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int val[n],wt[n];
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n ; i++)cin>>val[i];
        for(int i=0; i<n ; i++)cin>>wt[i];
        cout<<UnboundedKnapsack(val,wt,n,w)<<endl;

    }
}
