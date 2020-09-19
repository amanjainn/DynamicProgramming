/*
https://practice.geeksforgeeks.org/problems/largest-zigzag-sequence/0
*/


#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
 int mat[1005][1005];



int largestZig(int x,int y,int n)
{
    if(x<0 || y<0 || x>=n || y>=n)
        return 0;

     if(dp[x][y]!=0)
        return dp[x][y];


     dp[x][y]=mat[x][y];
     int maxSum=INT_MIN;
     for(int i=0;i<n ; i++){
         if(i!=y)
         maxSum=max(maxSum,largestZig(x+1,i,n));
     }
     return dp[x][y]+=maxSum;      

}

int main(){
    int t;
    cin>>t;
    while(t--) {
        int m;
        cin>>m;
        memset(mat,0,sizeof(mat));
        memset(dp,0,sizeof(dp));
        for(int i=0; i<m ; i++)
            for(int j=0; j<m ; j++)
                cin>>mat[i][j];

        int largest=INT_MIN;
        for(int i=0; i<m ; i++){
               largest=max(largest,largestZig(0,i,m));
        }
        cout<<largest<<endl;        
    }
}
