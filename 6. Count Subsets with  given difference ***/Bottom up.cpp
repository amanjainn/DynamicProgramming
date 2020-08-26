
/*
    Subset(s1)-Subset(s2)=diff; -----> 1
    Subset(s1)+ Subset(s2)=Totalsum -----> 2

    Add 1 and 2

    Subset(s1)= (diff+totalSum)/2;

    So basically the problems reduces to finding count of subset with sum s1

*/

#include<bits/stdc++.h>
using namespace std;


int CountSubsetSum(int arr[], int target,int n){
    int dp[n+1][target+1];
    for(int i=1; i<=target; i++){
        dp[0][i]=0;
    }
    for(int i=0 ; i<=n ; i++){
        dp[i][0]=1;
    }

    for(int i=1; i<=n ; i++){
        for(int j=1; j<=target ;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][target];

}

int main(){
    int n,diff;
    cin>>n>>diff;
    int arr[n];
    int sum=0;
    for(int i=0;i<n ; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if((diff+sum)%2!=0){
        cout<<0;
        return 0;
    }
    int s1=(diff+sum)/2; //DIFF+SUM SHOULD ALWAYS BE EVEN
    cout<<CountSubsetSum(arr,s1,n)<<endl;
}
