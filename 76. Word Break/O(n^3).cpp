class Solution {
    int  dp[350][350];
    set<string> st;
    public:
    bool solve(string &s, int low, int high){
        string str=s.substr(low,high-low+1);
        if(st.find(str)!=st.end())return true;
        if(low==high)return false;
        if(dp[low][high]!=-1)return dp[low][high];
        dp[low][high]=0;
        for(int k=low; k<high; k++){
            bool ans=solve(s,low,k) && solve(s,k+1,high);
            dp[low][high]|=ans;
        }
        return  dp[low][high];
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string s: wordDict){
            st.insert(s);
        }
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};
