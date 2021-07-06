class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<int,int>>dp(nums.size());
        int sum=0;
        for(int i=2; i<nums.size() ;i++){
            for(int j=i-1 ; j<nums.size() ;j++){
                if(nums[j]>nums[i])continue;
                int diff=nums[i]-nums[j];
                int curr = dp[j][diff];
                dp[i][diff]+=curr+1;
                sum+=curr;
            }
        }
        return sum;
        
    }
};
