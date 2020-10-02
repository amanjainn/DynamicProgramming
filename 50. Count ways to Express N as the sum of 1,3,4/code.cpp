#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

int dp[10004];

ll Ways(int n)
{
    if(n==0)
    return 1;
    
    if(dp[n]!=-1)
    return dp[n];
    
    ll ans=0;
    if(n-1>=0)
    ans=(Ways(n-1)%mod);
    
     if(n-3>=0)
    ans+=Ways(n-3)%mod;
    
     if(n-4>=0)
    ans+=Ways(n-4)%mod;
    
    return dp[n]=ans%mod;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    memset(dp,-1,sizeof(dp));
	    int n;
	    cin>>n;
	    cout<<Ways(n)<<endl;
	    
	}
	return 0;
}
