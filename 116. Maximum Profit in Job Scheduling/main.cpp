class Solution {
public:    
    int solve(vector<int>&dp,vector<int>&startTime,vector<int>&endTime,vector<int>&profit,int i, int n){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        if(i==n-1)return profit[i];
        auto it= lower_bound(startTime.begin()+i,startTime.end(),endTime[i]);
        int ans=max(solve(dp,startTime,endTime,profit,i+1,n),profit[i]);
        if(it!=startTime.end())
            ans=max(ans,profit[i]+solve(dp,startTime,endTime,profit,it-startTime.begin(),n));
        return dp[i]=ans;   
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>>info;
        for(int i= 0 ;i<n ; i++){
             info.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(info.begin(),info.end());
        for(int i=0; i<n; i++){
            startTime[i]=info[i][0];
            endTime[i]=info[i][1];
            profit[i]=info[i][2];
        }
        vector<int>dp(n,-1);
        return solve(dp,startTime,endTime,profit,0,n);
    }
};
