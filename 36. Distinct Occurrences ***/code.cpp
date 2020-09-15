/*
https://practice.geeksforgeeks.org/problems/distinct-occurrences/1
*/



#include<bits/stdc++.h>
using namespace std;

int dp[8004][300];
#define mod 1000000007
int distinctOccurence(int n, int m, string s, string t)
{
    for(int i=0; i<=n ;i++){
        dp[i][0]=1;
    }
    for(int j=1; j<=m ;j++){
        dp[0][j]=0;
    }
    for(int i=1; i<=n ; i++){
        for(int j=1 ;j<=m ;j++){
            if(s[i-1]!=t[j-1]){
                dp[i][j]=(dp[i-1][j])%mod;
            }else{
                dp[i][j]=dp[i-1][j]%mod+dp[i-1][j-1]%mod;
                dp[i][j]=dp[i][j]%mod;
            }
        }
    }
    return dp[n][m];

}
int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    cout<<distinctOccurence(n,m,s,t)<<endl;
}
