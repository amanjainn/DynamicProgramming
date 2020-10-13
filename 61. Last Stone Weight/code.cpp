class Solution {
public:
    
    void subsetSum(vector<int>&stones,bool dp[40][4000],int range, int n){
           for(int i=0; i<=range; i++){
               dp[0][i]=false;
           }
           for(int i=0; i<=n ;i++){
               dp[i][0]=true;
           }
           for(int i=1; i<=n; i++)
           {
               for(int j=1 ;j<=range ; j++)
               {
                   if(stones[i-1]>j){
                       dp[i][j]=dp[i-1][j];
                       continue;
                   }
                   dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
               }
           }        
    }

    int lastStoneWeightII(vector<int>& stones) {
           int range=0;
           for(int x:stones)
               range+=x;
           int  n=stones.size();
           bool dp[40][4000];
           subsetSum(stones,dp,range,n);
           int ans=INT_MAX;
           for(int i=1;i<=range; i++)
           {
               if(dp[n][i]){
                   int otherSum=range-i;
                   ans=min(ans,abs(i-otherSum));
               }
           }
        return ans;
    }
};
