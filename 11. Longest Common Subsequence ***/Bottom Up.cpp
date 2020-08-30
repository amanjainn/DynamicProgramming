#include <iostream>
using namespace std;




int Lcs(string X, string Y, int n,int m){
        int dp[n+1][m+1];
        for(int i=0; i<=n ;i++){
            dp[i][0]=0;
        }
        for(int j=0; j<=m ; j++){
            dp[0][j]=0;
        }
         
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=m ; j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        } 
       return dp[n][m]; 
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string X,Y;
        cin>>X>>Y;
        cout<<Lcs(X,Y,n,m)<<endl;
    }
}
