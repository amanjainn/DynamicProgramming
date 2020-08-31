/*
Link : https://leetcode.com/problems/shortest-common-supersequence/

*/



class Solution {
public:
    
    string lcs(string str1, string str2, int n, int m){
            int table[n+1][m+1];
            for(int i=0; i<=n ; i++){
                table[i][0]=0;
            }
            for(int j=0; j<=m ; j++){
                table[0][j]=0;
            }
        
            for(int i=1; i<=n ; i++){
                for(int j=1; j<=m ; j++){
                    if(str1[i-1]==str2[j-1]){
                        table[i][j]=1+table[i-1][j-1];
                        continue;
                    }
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
                }
            }
        int i=n,j=m;
        string ans="";
        while(i>0 && j>0){
                if(str1[i-1]==str2[j-1]){
                    ans+=str1[i-1];
                    i--;
                    j--;
                }else if(table[i-1][j]>table[i][j-1]){
                    ans+=str1[i-1];  
                    i--;
                }else{
                   ans+=str2[j-1];
                   j--;
                }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
    
    
    
    string shortestCommonSupersequence(string str1, string str2) {
            return lcs(str1,str2,str1.length(),str2.length());    
    }
};
