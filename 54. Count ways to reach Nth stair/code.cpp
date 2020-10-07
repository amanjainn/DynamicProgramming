#include<bits/stdc++.h>
using namespace std;

const long mod =1e9+7;


int main()
 {
	long dp[100005]={0};
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3 ;i<=100004 ;i++)
	{
	    dp[i]=(dp[i-1]%mod + dp[i-2]%mod)%mod;
	}
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cout<<dp[n]<<endl;
    }
}
