
#include<bits/stdc++.h>
using namespace std;

/*
Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
Time Complexity: O(N*W).

Auxiliary Space: O(N*W).

*/
int dp[1002][1002];

int maxProfit(int wt[],int prof[],int w, int n){
     if(n<0 || w==0)
        return 0;

      if(dp[w][n]!=-1){
          return dp[w][n];
      }
     if(wt[n]>w)
      return dp[w][n]=maxProfit(wt,prof,w,n-1);

    return dp[w][n]=max(maxProfit(wt,prof,w,n-1),prof[n]+maxProfit(wt,prof,w-wt[n],n-1));     
}

int main(){
    int n,weight;
    cin>>n;
    cin>>weight;
    int wt[n],prof[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>prof[i];
    for(int i=0;i<n;i++)cin>>wt[i];
    cout<<maxProfit(wt,prof,weight,n-1)<<endl;
    }
}
