/*
Link :  https://www.geeksforgeeks.org/friends-pairing-problem/
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[n+1]={0};
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n ;i++){
        dp[i]=dp[i-1] + (n-1)*dp[i-2];
    }
    cout<<dp[n]<<endl;
}
