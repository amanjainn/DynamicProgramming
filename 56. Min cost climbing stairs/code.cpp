https://leetcode.com/problems/min-cost-climbing-stairs/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
          int dp[1005]={0};
          dp[0]=cost[0];
          dp[1]=cost[1];
          for(int i=2;i<=cost.size();i++)
          {
              dp[i]=min(dp[i-1],dp[i-2])+(i==cost.size()?0:cost[i]);
          }
        return dp[cost.size()];
    }
};
