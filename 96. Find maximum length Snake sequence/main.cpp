#include <iostream>
using namespace std;
#define ll long long 

int n,m;
int mat[100][100];
int dp[100][100];

bool check(int i , int j  ){
     if(i<0 || j<0 || i>=n || j>=m)return false;
     return true;
}


int solve(int i, int j){
       if(dp[i][j]!=-1)return dp[i][j];
       int temp=0;
       if(check(i+1,j) && abs(mat[i][j]-mat[i+1][j])==1){
           temp=solve(i+1,j);
       }
       if(check(i,j+1)){
            temp=max(temp,solve(i,j+1));
       }
       return dp[i][j]=1+temp;
}


int main() {
    cin>>n>>m;
    for(int i=0 ;i<n ; i++){
        for(int j=0; j<m ;j++){
            cin>>mat[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0; i<n ; i++){
        for(int j=0; j<m ;j++){
            ans=max(ans,solve(i,j)); 
        }
    }
    cout<<ans<<endl;
}
