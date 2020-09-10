
/*
Link : https://leetcode.com/problems/longest-increasing-subsequence/submissions/
T: O(n^2)
S: O(n)
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[10000]={0};
        int len=0;
        for(int i =0 ; i<n ;i++){
            dp[i]=1;
            for(int j=i-1 ; j>=0 ; j--){
                if(nums[j]>=nums[i])
                    continue;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        for(int i=0 ; i<n ;i++){
            len=max(len,dp[i]);
        }
        return len;
    }
};
