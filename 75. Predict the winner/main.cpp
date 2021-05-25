class Solution {
    long long dp[100][100];
public:
  
long long  OptimalGame(vector<int> &arr,int low, int  high)
{
    if(low>high)
    return 0;

    if(dp[low][high]!=-1)
        return dp[low][high];

    long long op1=arr[low]+ min(OptimalGame(arr,low+2,high),OptimalGame(arr,low+1,high-1));    
    long long op2=arr[high]+ min(OptimalGame(arr,low,high-2),OptimalGame(arr,low+1,high-1));
    return dp[low][high]=max(op1,op2);    
}
    bool PredictTheWinner(vector<int>& nums) {
     
        memset(dp,-1,sizeof(dp));
        long long ans=OptimalGame(nums,0,nums.size()-1);
        long long sum=accumulate(nums.begin(),nums.end(),0);
        return ans>=(sum-ans);
    }
};
