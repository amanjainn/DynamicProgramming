#include<bits/stdc++.h>
using namespace std;


int UnboundedKnapsack(int val[],int wt[],int n,int w){
    int dp[n+1][w+1];
    for(int i=0 ; i<=w; i++){
        dp[0][i]=0;
    }
    for(int i=0; i<=n ;i++){
        dp[i][0]=0;
    }
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=w; j++){
            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
                continue;
            }
            dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int val[n],wt[n];
        for(int i=0; i<n ; i++)cin>>val[i];
        for(int i=0; i<n ; i++)cin>>wt[i];
        cout<<UnboundedKnapsack(val,wt,n,w)<<endl;
    }
}
