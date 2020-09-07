Optimized to 1D DP
Complexity:
C++/Java O(KlogN) Time, O(K) Space
Python O(min(K, logN)^2) Time, O(min(K, logN)) Space


C++:

    int superEggDrop(int K, int N) {
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++)
            for (int k = K; k > 0; --k)
                dp[k] += dp[k - 1] + 1;
        return m;
    }
