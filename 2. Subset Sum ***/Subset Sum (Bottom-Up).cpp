#include<bits/stdc++.h>
using namespace std;

int subsetSum(int arr[],int n, int target){
     int table[n+1][target+1];
     for(int i=0;i<=n;i++){
         for(int j=0; j<=target ;j++){
             if(i==0){
                 table[i][j]=0;
             }
             if(j==0){
                 table[i][j]=1;
             }
         }
     }
     table[0][0]=1;
     for(int i=1 ; i<=n ;i++){
         for(int j=1; j<=target ;j++){
             if(arr[i-1]>j){
                 table[i][j]=table[i-1][j];
                 continue;
             }
             table[i][j]=table[i-1][j] || table[i-1][j-arr[i-1]];
         }
     }
     return table[n][target];
}




int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0; i<n ;i++)cin>>arr[i];
    cout<<(subsetSum(arr,n,target)?"YES":"NO")<<endl;
}
