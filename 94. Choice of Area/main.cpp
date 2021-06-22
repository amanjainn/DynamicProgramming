
Problem link : https://www.geeksforgeeks.org/game-theory-choice-area/


#include <bits/stdc++.h> 
using namespace std; 
  

int maxSurvival(int A, int B, vector<vector<int>>& dp, pair<int, int> X, pair<int, int> Y, 
                pair<int, int> Z, bool f1, bool f2, bool f3) {
    if (A<=0 || B<=0) 
        return -1;  
    if(dp[A][B]!=-1) 
        return dp[A][B]; 
    int x=INT_MIN, y=INT_MIN, z=INT_MIN, ans;
    if(f1)
        x=1+maxSurvival(A + X.first, B + X.second, dp,
                                   X, Y, Z, 0, 1, 1);
    if(f2)
        y=1+maxSurvival(A + Y.first, B + Y.second, dp,
                                   X, Y, Z, 1, 0, 1);
    if(f3)
        z=1+maxSurvival(A + Z.first, B + Z.second, dp,
                                   X, Y, Z, 1, 1, 0);
    ans=max(x, max(y, z));
    dp[A][B]=ans;
    return ans; 
} 
  

int main() 
{ 
    pair<int, int> X={3, 2}, Y={-5, -10}, Z={-20, 5}; 
  
    int A = 20; 
    int B = 8; 
    vector<vector<int>> dp(1000, vector<int>(1000, -1));
    cout << maxSurvival(A, B, dp, X, Y, Z, 1, 1, 1)<<endl; 
  
    return 0; 
} 
