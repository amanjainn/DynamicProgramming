class Solution {
public:   
    void solve(int i, string s, vector<vector<int>> &dp, vector<vector<string>>&ans , vector<string> vc){
         if(i==s.size()){
             ans.push_back(vc);
         }           
         for(int k=i ; k<s.size() ;k++){
               string str= s.substr(i,k-i+1);
               if(dp[i][k]==1){              
                     vc.push_back(str);
                     solve(k+1,s,dp,ans,vc);
                     vc.pop_back();
               }
          
         }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap=0 ; gap<n ; gap++){
             for(int i=0,j=gap ; j<n ; j++,i++){
                 if(gap==0)
                     dp[i][j]=true;
                 else if(gap==1)
                     dp[i][j]=s[i]==s[j];
                 else 
                     dp[i][j]=s[i]==s[j] && dp[i+1][j-1]==1;
             }
        }
        vector<vector<string>>ans;
        vector<string> vc;
        solve(0,s,dp,ans,vc);
        return ans;
    }
};
