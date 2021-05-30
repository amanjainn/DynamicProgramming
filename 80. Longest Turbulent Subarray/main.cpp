class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int dp1[n],dp2[n];
        fill(dp1,dp1+n,1);
        fill(dp2,dp2+n,1);
        for(int i=n-2; i>=0 ; i--){
             if(i&1){
                 if(arr[i]<arr[i+1])
                     dp1[i]+=dp1[i+1];
             } else{
                 if(arr[i]>arr[i+1])
                     dp1[i]+=dp1[i+1];
             }  
        }
        
        for(int i=n-2 ;i>=0 ;i--){
              if(i%2==0){
                 if(arr[i]<arr[i+1])
                     dp2[i]+=dp2[i+1];
             } else{
                 if(arr[i]>arr[i+1])
                     dp2[i]+=dp2[i+1];
             }
        }
        
        return max(*max_element(dp1,dp1+n),*max_element(dp2,dp2+n));
        
        
    }
};
