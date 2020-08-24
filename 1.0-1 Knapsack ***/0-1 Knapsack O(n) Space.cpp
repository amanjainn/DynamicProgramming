#include<bits/stdc++.h>
using namespace std;


int maxProfit(int wt[],int prof[],int w, int n){
     int table[w+1];
     for(int i=0; i<=w; i++){
            table[i]=0;
     }
     for(int i=1;i <=n ;i++){
         for(int j=w; j>=1; j--){
             if(wt[i-1]>j){
                 continue;
             }
             table[j]=max(table[j],prof[i-1]+table[j-wt[i-1]]);

         }
     }
    return table[w];

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
