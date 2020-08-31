/*
Link : https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0

*/


#include<bits/stdc++.h>
using namespace std;

int LCS(string s,string p,int n, int m){
        int table[n+1][m+1];
        for(int i=0; i<=n ; i++){
            table[i][0]=0;
        }
        for(int j=0; j<=m ; j++){
            table[0][j]=0;
        }
        for(int i=1; i<=n ; i++){
            for(int j=1;j<=m ; j++){
                if(s[i-1]==p[j-1]){
                    table[i][j]=1+table[i-1][j-1];
                    continue;
                }
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
        return table[n][m];
}




int main(){
    int t;
    cin>>t;
    while(t--){
        string str1,str2;
        cin>>str1>>str2;
        int n=str1.length();
        int m=str2.length();
        int lcs=LCS(str1,str2,n,m);
        cout<<(m+n-lcs)<<endl;
    }
}
