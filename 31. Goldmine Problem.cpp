/*
https://practice.geeksforgeeks.org/problems/gold-mine-problem/0
T: O(n^2)
*/


#include<bits/stdc++.h>
using namespace std;

int graph[100][100];
int dp[100][100];
#define mod 1000000007

bool verify(int i,int j, int n, int m){
     if(i<0 || j<0 || i>=n || j>=m)
        return false;
        return true;
}


int goldmine(int i, int j, int n, int m)
{
      if(dp[i][j]!=0)
            return dp[i][j];

      int result=INT_MIN;
      if(verify(i,j+1,n,m)){
        result=max(result,goldmine(i,j+1,n,m)+graph[i][j+1]);
           dp[i][j]=result%mod;
      }

      if(verify(i+1,j+1,n,m)){
        result=max(result,goldmine(i+1,j+1,n,m)+graph[i+1][j+1]);
           dp[i][j]=result%mod;
      }

      if(verify(i-1,j+1,n,m)){
        result=max(result,goldmine(i-1,j+1,n,m)+graph[i-1][j+1]);  
        dp[i][j]=result%mod;
      }

      return dp[i][j];      
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        memset(graph,0,sizeof(graph));
        for(int i=0; i<n ; i++)
            for(int j=0; j<m ;j++)
                 cin>>graph[i][j];

       
         int ans=INT_MIN;
         memset(dp,0,sizeof(graph));
         for(int i=0; i<n ;i++)
         {
             ans=max(ans,goldmine(i,0,n,m)+graph[i][0]);
         }
         cout<<ans<<endl;    
    }
}
