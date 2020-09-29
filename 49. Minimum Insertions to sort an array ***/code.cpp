/*
https://practice.geeksforgeeks.org/problems/minimum-insertions-to-sort-an-array0535/1

*/


#include<bits/stdc++.h>
using namespace std;

int dp[10000];

int main()
{
       int n;
       cin>>n;
       int arr[n];
       for(int i=0; i< n ;i++){
           cin>>arr[i];
       }
       memset(dp,0,sizeof(dp));
       for(int i=0; i<n ; i++){
           dp[i]=1;
           for(int j=i-1 ;j>=0 ; j--)
           {
                if(arr[j]>arr[i])continue;

                dp[i]=max(dp[i],1+dp[j]);
           }
       }
       int lis=0;
       for(int i=0;i<n ; i++){
           lis=max(dp[i],lis);
       }
       cout<<n-lis<<endl;

}
