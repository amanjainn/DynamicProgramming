/*
Link : https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
*/

#include<bits/stdc++.h>
using namespace std;


int lcs(string str, string temp, int n){
    int dp[n+1][n+1];
    for(int i=0 ;i<=n ; i++){
        dp[i][0]=0;
    }
    for(int j=0; j<=n ; j++){
        dp[0][j]=0;
    }

    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n ;j++){
            if(str[i-1]==temp[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                continue;
            }
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }
    return dp[n][n];
}  
    
    int minInsertions(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        int p=lcs(s,temp,s.length());
        return (s.length()-p);
    }




int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    cout<<minInsertions(str)<<endl;
	}
	return 0;
}
