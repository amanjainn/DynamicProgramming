/*
Link : https://leetcode.com/problems/palindrome-partitioning-ii/

*/


#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string str, int i,int j){
    string temp=str.substr(i,j);
    string rev=temp;
    reverse(rev.begin(),rev.end());
    return rev==temp;
}

int palindromePartition(string str,int i, int j){
     if(i==j)
        return 0;
   
     if(dp[i][j]!=-1)
        return dp[i][j];
       
     if(isPalindrome(str,i,j)){
         return 0;
     }   

     int ans=INT_MAX;
     for(int k=i ; k<j ;k++){
         int temp=palindromePartition(str,i,k)+palindromePartition(str,k+1,j)+1;
         ans=min(temp,ans);
     }
     return dp[i][j]=ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        memset(dp,-1,sizeof(dp));
        cout<<palindromePartition(str,0,str.length()-1)<<endl;

    }
}
