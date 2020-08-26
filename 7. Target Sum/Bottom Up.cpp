
Link : https://leetcode.com/problems/target-sum/

class Solution {
public:
    
int CountSubsetSum(vector<int> arr, int target,int n){
    int dp[n+1][target+1];
    for(int i=1; i<=target; i++){
        dp[0][i]=0;
    }
    for(int i=0 ; i<=n ; i++){
        dp[i][0]=1;
    }

    for(int i=1; i<=n ; i++){
        for(int j=0; j<=target ;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][target];
}

    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(int x: nums)sum+=x;
     
        if(S>sum || (sum+S)%2!=0)
            return 0;
           int target=(sum+S)/2;
        return CountSubsetSum(nums,target,nums.size());
    }
};
