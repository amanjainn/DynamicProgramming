T:O(n^2)
S:O(n^2)


#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int OptimalGame(int arr[],int low, int  high)
{
    if(low>high)
    return 0;

    if(dp[low][high]!=-1)
        return dp[low][high];

    int op1=arr[low]+ min(OptimalGame(arr,low+2,high),OptimalGame(arr,low+1,high-1));    
    int op2=arr[high]+ min(OptimalGame(arr,low,high-2),OptimalGame(arr,low+1,high-1));
    return dp[low][high]=max(op1,op2);    
}


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n ;i++)cin>>arr[i];
        cout<<OptimalGame(arr,0,n-1)<<endl;
    }
}
