class Solution {
    map<pair<string,string>,int> mp;
public:
    bool solve(string s1,string s2){
       if(s1.size()==1)
            return s1==s2;
       if(mp.find({s1,s2})!=mp.end())return mp[{s1,s2}];
       bool ans=false; 
       for(int i=0; i<s1.size() ;i++){
           ans = ans || ((solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i))))||(solve(s1.substr(0,i),s2.substr(s2.size()-i)) &&  solve(s1.substr(i),s2.substr(0,s2.size()-i)));    
       }
        return mp[{s1,s2}]=ans;
    }

    bool isScramble(string s1, string s2) {
         mp.clear();
         return solve(s1,s2);
    }
};
