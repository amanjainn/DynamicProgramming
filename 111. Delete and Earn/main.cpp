class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size()  ;i++){
            mp[nums[i]]++;
        }
        int cur=mp[1],prev=0;
        for(int i=2 ;i<=1000 ; i++){
             int next=max(cur,i*mp[i]+prev);
             prev=cur;
             cur=next;
        }
        return max(prev,cur);
    }
};
