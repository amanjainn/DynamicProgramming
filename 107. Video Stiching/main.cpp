Sort clips first.
Then for each clip, update dp[clip[0]] ~ dp[clip[1]].

Time O(NlogN + NT), Space O(T)

C++

    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        vector<int> dp(101, 101);
        dp[0] = 0;
        for (auto& c : clips)
            for (int i = c[0] + 1; i <= c[1]; i++)
                dp[i] = min(dp[i], dp[c[0]] + 1);
        return dp[T] >= 100 ? -1 : dp[T];
    }
