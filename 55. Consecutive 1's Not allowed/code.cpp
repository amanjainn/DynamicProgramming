class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    const ll mod=1e9+7;
	    ll last1=1;
	    ll last0=1;
	    for(int i=2; i<=n ; i++)
	    {
	        ll newLast0=(last1+last0)%mod;
	        ll newLast1=last0%mod;
	        last1=newLast1;
	        last0=newLast0;
	    }
	    return (last1+last0)%mod;
	}
};
