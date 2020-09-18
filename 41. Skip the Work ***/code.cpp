/*
Link : https://practice.geeksforgeeks.org/problems/skip-the-work/0
*/


class Solution
{
  public:
    int minAmount(int A[] , int N)
    {
        int inclu=A[0];
        int exclu=0;
        for(int i=1; i<N; i++)
        {
            int newInclu=min(inclu,exclu)+A[i];
            exclu=inclu;
            
            inclu=newInclu;
        }
        return min(inclu,exclu);
    }
};
