class Solution {
      int dp[105][105][105];
public:
    
    int solve(int low, int high,vector<pair<int,int>> &groups,int extra){
        if(low>high)return 0;
     
        if(dp[low][high][extra]!=-1)return dp[low][high][extra];
        
        int temp=groups[low].second+extra;
        int ans=temp * temp +  solve(low+1,high,groups,0);
        int other=INT_MIN;
        for(int s=low+1 ; s<=high ; s++){ 
            if(groups[s].first==groups[low].first)
            other=max(other,solve(s,high,groups,extra+groups[low].second)+  solve(low+1,s-1,groups,0));
        }
        return dp[low][high][extra]=max(ans,other);
    }
    int removeBoxes(vector<int>& boxes) {
       vector<pair<int,int>>groups;
       memset(dp,-1,sizeof(dp));
       int high=1,count=1;
       while(high<boxes.size()){
            if(boxes[high]!=boxes[high-1]){
                groups.push_back({boxes[high-1],count});
                count=1;
            }else{
                count++;
            }
           high++;
       }
        groups.push_back({boxes[high-1],count});
        return solve(0,groups.size()-1,groups,0);
    }
};
