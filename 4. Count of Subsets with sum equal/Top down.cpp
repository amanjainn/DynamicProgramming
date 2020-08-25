#include<bits/stdc++.h>
using namespace std;


/*
Link : https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
O(n^2) -Time
O(n^2) -Space
*/

int dp[102][50001];
int subsetSum(int arr[],int n, int target){
      if(target==0)
        return 1;

      if(n<0 || target<0)
       return 0;

      if(dp[n][target]!=-1)
        return dp[n][target];

      if(arr[n]>target){
          return dp[n][target]=subsetSum(arr,n-1,target);
      }
      return dp[n][target]=subsetSum(arr,n-1,target)+ subsetSum(arr,n-1,target-arr[n]);
}



int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n  ;i++)cin>>arr[i];
    cout<<(subsetSum(arr,n-1,target)<<endl;
    
}
