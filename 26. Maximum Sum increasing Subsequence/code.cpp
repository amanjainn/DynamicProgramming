#include<bits/stdc++.h>
using namespace std;

int dp[200001];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n ; i++){
            cin>>arr[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=0 ;i<n ; i++){
            dp[i]=arr[i];
            for(int j=i-1; j>=0 ; j--)
            {
                if(arr[j]>=arr[i])
                continue;
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
        }
        int maxAns=0;
        for(int i=0; i<n ; i++){
            maxAns=max(maxAns,dp[i]);
        }
        cout<<maxAns<<endl;
        
    }
}
