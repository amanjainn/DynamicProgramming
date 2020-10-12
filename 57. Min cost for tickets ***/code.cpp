class Solution {
     int dp[366];
public:
    
    int getMinCost(vector<int> &days, vector<int> &costs, int i)
    {
            if(i>=days.size())return 0;
            if(dp[i]!=0)return dp[i];
            int op1=costs[0]+getMinCost(days,costs,i+1);
            
            int k=i;
            int n=days.size();
            for(; k<n ;k++)
            {
                if(days[k]>=days[i]+7)
                    break;
            }
            int op2=costs[1]+getMinCost(days,costs,k);
            k=i;
            for(; k<n ;k++)
            {
                if(days[k]>=days[i]+30)
                    break;
            }
            int op3=costs[2]+getMinCost(days,costs,k);
            dp[i]=min(op1,min(op2,op3));
            return dp[i];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,0,sizeof(dp));
        return getMinCost(days,costs,0);
    }
};
