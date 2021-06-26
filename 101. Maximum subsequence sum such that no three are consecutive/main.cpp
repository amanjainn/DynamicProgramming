#include<bits/stdc++.h>
using namespace std;


int main(){
     int n;cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)cin>>arr[i];
     int sum[n]={0};
     if(n>=1)sum[0]=arr[0];
     if(n>=2)sum[1]=arr[0]+arr[1];
     if(n>2)sum[2]=max(sum[1],max(arr[1]+arr[2],arr[0]+arr[2]));
     for(int i=3 ;i<n;i++){
            sum[i]=max(sum[i-1],max(arr[i]+sum[i-2],arr[i]+arr[i-1]+sum[i-3]));
     }
     cout<<sum[n-1]<<endl;
     
}
