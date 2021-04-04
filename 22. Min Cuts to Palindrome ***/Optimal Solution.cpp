int palindromicPartition(string s)
{
          if (s.empty())
                    return 0;
          int n = s.size();
          vector<vector<bool>>dp(n, vector<bool>(n, false));
          for (int gap = 0; gap < s.length() ; gap++) {
                    for (int i = 0, j = gap; j < s.length(); i++, j++) {
                              if (gap == 0) {
                                        dp[i][j] = true;
                              } else if (gap == 1) {
                                        dp[i][j] = (s[i] == s[j]);
                              } else {
                                        dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
                              }
                    }
          }
         
          int ans[n];
          ans[0] = 0;
          for (int i = 1; i < n ; i++) {
                    if (dp[0][i]) {
                              ans[i] = 0;
                              continue;
                    }
                    ans[i] = INT_MAX;
                    for (int j = i ; j > 0 ; j--) {
                              if (dp[j][i]) {
                                        if (ans[j - 1] + 1 < ans[i]) {
                                                  ans[i] = ans[j - 1] + 1;
                                        }
                              }
                    }
          }
          return ans[n - 1];
}
