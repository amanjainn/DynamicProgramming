/*
Link : https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
T: O(n^2)
S: O(n^2)
*/


#include <bits/stdc++.h>
using namespace std;


int dp[501][501];


int Lcs(string X, string Y, int n,int m){
        if(n==0 || m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];

        if(X[n-1]==Y[m-1])
             return dp[n][m]=1+Lcs(X,Y,n-1,m-1);
             
        return dp[n][m]=max(Lcs(X,Y,n-1,m),Lcs(X,Y,n,m-1));     
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string X,Y;
        cin>>X>>Y;
        memset(dp,-1,sizeof(dp));
        cout<<Lcs(X,Y,n,m)<<endl;
    }
}
