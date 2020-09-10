/*
Read about Patience Sort
*/



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> seq;
        if(n==0)
            return 0;
        seq.push_back(nums[0]);
        for(int i=1 ;i<n ; i++)
        {
            if(nums[i]>seq.back())
                seq.push_back(nums[i]);
            else{
                int p=lower_bound(seq.begin(),seq.end(),nums[i])-seq.begin();
                seq[p]=nums[i];
            }
        }
        return seq.size();
    }
};
