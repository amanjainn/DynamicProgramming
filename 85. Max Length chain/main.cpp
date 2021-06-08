bool comp (struct val &a,struct val &b){
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
      int dp[n]={0};
      int ans=1;
      
      sort(p,p+n,comp);
      for(int i=0 ; i<n ; i++){
          dp[i]=1;
          for(int j=i-1; j>=0; j--){
              if(p[i].first>p[j].second){
                  dp[i]=max(dp[i],1+dp[j]);              
                  ans=max(ans,dp[i]);
              }
          }
      }
   
      return ans;
}
