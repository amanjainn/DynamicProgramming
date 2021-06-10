class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int cur_min=1,cur_max=1;
        for(int i= 0; i<nums.size() ;i++){
              if(nums[i]==0){
                  cur_min=1,cur_max=1;
                  ans=max(ans,0);
                  continue;
              }
            int store_max=cur_max;
            cur_max=max(nums[i],nums[i]*cur_max);
            cur_max=max(cur_max,cur_min*nums[i]);
            cur_min=min(cur_min*nums[i],nums[i]);
            cur_min=min(store_max*nums[i],cur_min);
            ans=max(ans,cur_max);
        }
        return ans;
    }
};
