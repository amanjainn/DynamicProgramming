/*
Link : https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0
*/

#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSub(string str, string str1, int n, int m){
  
     int table[n+1][n+1];
     for(int i=0; i<=n ;i++){
         table[i][0]=0;
     }
     for(int j=0; j<=n ; j++){
         table[0][j]=0;
     }
     for(int i=1;i<=n ; i++){
        for(int j=1; j<=n ; j++){
            if(str[i-1]==str1[j-1]){
                table[i][j]=1+table[i-1][j-1];
                continue;
            }
            table[i][j]=max(table[i-1][j],table[i][j-1]);
         }
     }
     return table[n][n];
}



int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        string temp=str;
        reverse(temp.begin(),temp.end());
        int n=str.length();
        cout<<longestPalindromeSub(str,temp,n,n)<<endl;
    }
}
