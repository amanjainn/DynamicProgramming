/*
Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
T: O(n^2)
S: O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;

int subsetSum(int arr[],int n, int target){
    bool table[n+1][target+1];
 
     for(int i=1; i<=target;i++)
        table[0][i]=false;

     for(int i=0; i<=n ;i++)
        table[i][0]=true;   

     for(int i=1 ; i<=n ;i++){
         for(int j=1; j<=target ;j++){
             if(arr[i-1]>j){
                 table[i][j]=table[i-1][j];
             }else
             table[i][j]=table[i-1][j] || table[i-1][j-arr[i-1]];
         }
     }
     return table[n][target];
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        int arr[n];
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
