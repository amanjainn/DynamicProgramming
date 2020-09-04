/*
  T: O(n^3)
  S: O(n^2)
  Link :  https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0

*/



#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];

int TBP(string str, int i, int j, bool target){
        if(dp[i][j][target]!=-1)
            return dp[i][j][target];

        if(i>j){
            return dp[i][j][target]=0;
        }    

        if(i==j){
            if(target==true){
                if(str[i]=='T')
                     return dp[i][j][target]=1;
                 else 
                     return dp[i][j][target]=0;    
            }else{
                if(str[i]=='F')
                     return dp[i][j][target]=1;
                  else
                     return dp[i][j][target]=0;
            }
        }
        int ans=0;
        for(int k=i+1; k<j ; k+=2){
                    int lt,lf,rt,rf;
                    
        
                    if(dp[i][k-1][true]==-1){
                        lt=TBP(str,i,k-1,true);
                    }else {
                        lt=dp[i][k-1][true];
                    }
                    
                    if(dp[i][k-1][false]==-1){
                        lf=TBP(str,i,k-1,false);
                    }else {
                        lf=dp[i][k-1][false];
                    }
                    
                    if(dp[k+1][j][true]==-1){
                        rt=TBP(str,k+1,j,true);
                    }else {
                        rt=dp[k+1][j][true];
                    }
                    
                    if(dp[k+1][j][false]==-1){
                        rf=TBP(str,k+1,j,false);
                    }else {
                        rf=dp[k+1][j][false];
                    }
            
                    if(str[k]=='&'){
                        if(target==true)
                          ans+=lt*rt;
                        else 
                          ans+=lt*rf+lf*rt+lf*rf;
                    }
                    if(str[k]=='|'){
                         if(target==true)
                           ans+=lt*rt+lt*rf+rt*lf;
                         else 
                            ans+=lf*rf;  
                    }
                    if(str[k]=='^'){
                         if(target==true)
                             ans+=lt*rf+lf*rt;
                         else
                             ans+=lt*rt+lf*rf;
                         
                    }              
        }
        return  dp[i][j][target]=ans%1003;

}

int main(){
       int t;
       cin>>t;
       while(t--){
           memset(dp,-1,sizeof(dp));
           int n;cin>>n;
           string str;cin>>str;
           cout<<TBP(str,0,n-1,true)<<endl;
       }
}
