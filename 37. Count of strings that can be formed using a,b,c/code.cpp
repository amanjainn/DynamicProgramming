/*
Link :  https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1005][2][3];

int CountStrings(int b, int c, int n)
{
    if(n==0 || (b==0 && c==0))
        return 1;

    if(dp[n][b][c]!=0)
        return dp[n][b][c];

    if(b!=0)
      dp[n][b][c]=CountStrings(b-1,c,n-1);

    if(c!=0)
      dp[n][b][c]+=CountStrings(b,c-1,n-1);

      dp[n][b][c]+=CountStrings(b,c,n-1);
      return dp[n][b][c];

}

int main()
{
     int t;
     cin>>t;
     while(t--)
     {
         memset(dp,0,sizeof(dp));
         int n;
         cin>>n;
         cout<<CountStrings(2,1,n)<<endl;
     }
}
