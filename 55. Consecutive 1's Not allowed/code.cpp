class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    const ll mod=1e9+7;
	    ll dp[100005]={0};
	    dp[1]=2;
	    dp[2]=3;
	    dp[3]=5;
	    for(int i=4; i<=n ; i++)
	    {
	        dp[i]=(dp[i-1]+dp[i-2])%mod;
	    }
	    return dp[n];
	}
};
