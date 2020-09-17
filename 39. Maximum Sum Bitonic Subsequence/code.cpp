/*
Link :https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0
*/


#include<bits/stdc++.h>
using namespace std;

  int MaximumBitonicSequence(vector<int>nums)
	{
	    int dp1[1000005],dp2[1000005];
	    memset(dp1,0,sizeof(dp1));
	    memset(dp2,0,sizeof(dp2));
	    for(int i=0; i<nums.size() ;i++){
	        dp1[i]=nums[i];
	        for(int j=i-1 ; j>=0; j--){
	            if(nums[j]>=nums[i])
	            continue;
	            dp1[i]=max(dp1[i],dp1[j]+nums[i]);
	        }
	      
	    }
	     for(int i=nums.size()-1; i>=0 ;i--){
	         dp2[i]=nums[i];
	
	        for(int j=i+1 ; j<nums.size(); j++){
	            if(nums[j]>=nums[i])
	            continue;
	            dp2[i]=max(dp2[i],dp2[j]+nums[i]);
	        }
	        
	    }
	    int longest=0;
	    for(int  i=0 ;i<nums.size();i++){
	        longest=max(longest,dp1[i]+dp2[i]-nums[i]);
	    }
	    return longest;
	}



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> arr;
        for(int i=0; i< n; i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cout<<MaximumBitonicSequence(arr)<<endl;
        
    }
	return 0;
}                                    
