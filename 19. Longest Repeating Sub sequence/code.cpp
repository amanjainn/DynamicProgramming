/*
Link : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
*/


#include<bits/stdc++.h>
using namespace std;

int lcs(string str, string temp, int n,int m){
    int dp[n+1][m+1];
    for(int i=0 ;i<=n ; i++){
        dp[i][0]=0;
    }
    for(int j=0; j<=m ; j++){
        dp[0][j]=0;
    }

    for(int i=1; i<=n ; i++){
        for(int j=1; j<=m ;j++){
            if(str[i-1]==str[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
                continue;
            }
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }
    return dp[n][m];
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        string temp=str;
        reverse(temp.begin(),temp.end());
        cout<<lcs(str,temp,n,n)<<endl;
    }
}
