class Solution {
    unordered_map<string,int>mp;
public:
    bool solve(string &nums , int t){
         if(mp.count(nums))return mp[nums];
         if(nums[nums.size()-1]-'0'>=t)return mp[nums]=true;
         for(int i=0; i<nums.size() ;i++){ 
               string cur =nums.substr(0,i)+nums.substr(i+1);  
                  if(!solve(cur,t-(nums[i]-'0'))){
                     return mp[nums]=true;
                  }
              }
        return mp[nums]=false;
    }
    bool canIWin(int num, int t) {
        if((num+1)*(num)/2<t)return 0;
        if(t==0)return 1;
        string nums="";        
        for(int i=1 ;i<=num ; i++)nums.push_back(i+'0');
        return solve(nums,t);
    }
};
