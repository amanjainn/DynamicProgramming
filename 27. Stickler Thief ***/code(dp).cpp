/*
Link : https://practice.geeksforgeeks.org/problems/stickler-theif/0
T: O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;


int dp[10001];

int stickler(int arr[],int n)
{
    if(n<=0)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    return dp[n]=max(stickler(arr,n-2)+arr[n-1],stickler(arr,n-1));       
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n ;i++)
        {
            cin>>arr[i];
        }
        memset(dp,0,sizeof(dp));
        cout<<stickler(arr,n)<<endl;
    }
}
