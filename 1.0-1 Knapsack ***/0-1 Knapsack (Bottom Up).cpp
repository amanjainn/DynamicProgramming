#include<bits/stdc++.h>
using namespace std;


int maxProfit(int wt[],int prof[],int w, int n){
     int table[n+1][w+1];
     for(int i=0; i<=n; i++){
         for(int j=0;j<=w;j++){
             if(i==0 ||j==0)
            table[i][j]=0;
         }
     }
     for(int i=1;i <=n ;i++){
         for(int j=1; j<=w; j++){
             if(wt[i-1]>j){
                 table[i][j]=table[i-1][j];
                 continue;
             }
             table[i][j]=max(table[i-1][j],prof[i-1]+table[i-1][j-wt[i-1]]);

         }
     }
    return table[n][w];

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,weight;
        cin>>n>>weight;
        int wt[n],prof[n];
            for(int i=0;i<n;i++)cin>>prof[i];
            for(int i=0;i<n;i++)cin>>wt[i];
        cout<<maxProfit(wt,prof,weight,n)<<endl;
    }
}
