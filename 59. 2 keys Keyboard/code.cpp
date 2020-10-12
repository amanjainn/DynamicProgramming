class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        if(n==2)return 2;
        int prev[n+1];
        prev[1]=0;
        prev[2]=2;
        for(int i=3; i<=n ;i++)
        {
            prev[i]=i;
            int j=i/2;
            while(j>=1)
            {
                if(i%j==0)
                prev[i]=min(prev[i],prev[j]+i/j);
                j--;
            }
      
        }
        return prev[n];
    }
};
