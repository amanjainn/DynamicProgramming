class Solution {
  
    
public:
    int leastNum(vector<int> perSqs, int target)
    {
          int dp[target+1];
          dp[0]=0;
          for(int i=1 ; i<=target ;i++)
              dp[i]=INT_MAX;
          
          for(int i=1; i<=target ;i++)
          {
              for(int j=0; j<perSqs.size() ; j++)
              {
                    if(i-perSqs[j]<0)
                        continue;
                    int curr=dp[i-perSqs[j]];
                    if(curr!=INT_MAX)
                    {
                        dp[i]=min(dp[i],curr+1);
                    }
              }
          }
        return dp[target];
    }
    bool perfectSqr(int num)
    {
        int res=sqrt(num);
        if(res*res==num)
            return true;
        return false;
    }

    int numSquares(int n) {
            vector<int> perSqs;
            for(int i=1; i<=n ; i++)
            {
                  if(perfectSqr(i))
                      perSqs.push_back(i);
            }

        return leastNum(perSqs,n);
        
    }
};
