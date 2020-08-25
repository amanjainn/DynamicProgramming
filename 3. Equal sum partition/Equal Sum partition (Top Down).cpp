#include<bits/stdc++.h>
using namespace std;

int dp[103][50003];

int subsetSum(int arr[],int n, int target){
        if(target==0)
            return 1;
        if(n<0 || target<0)
            return 0;

        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        if(arr[n]>target){
            return dp[n][target]=subsetSum(arr,n-1,target);
        }
        return dp[n][target]= subsetSum(arr,n-1,target) || subsetSum(arr,n-1,target-arr[n]);     

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        int arr[n];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum &1){
            cout<<"NO"<<endl;
        }else{
            cout<<(subsetSum(arr,n-1,sum/2)?"YES":"NO")<<endl;
        }
    }
}
