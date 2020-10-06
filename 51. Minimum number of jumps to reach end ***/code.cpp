https://leetcode.com/problems/jump-game-ii/submissions/



T: O(n)
S: O(1)




class Solution {
public:
    int jump(vector<int>& nums) {
             int steps=nums[0];
             int maxReachable=nums[0];
             int jumps=1;
             if(nums.size()==1)return 0;
             for(int i=1; i<nums.size();i++)
             {
                 if(i==nums.size()-1)return jumps;
                 maxReachable= max(maxReachable,i+nums[i]);
                 steps--;
                 if(steps==0)
                 {
                    jumps++;
                    if(i>=maxReachable)return -1; //Not required if solution always exist
                    steps=maxReachable-i;
                 }
             }
        return jumps;
        
    }
};
