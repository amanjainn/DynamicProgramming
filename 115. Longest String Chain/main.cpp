class Solution {
 vector<vector<int>> edges;
 vector<int> cache;
public:
    int longest(int src){
         if(cache[src]>0)return cache[src];
         cache[src]=1;
         for(int next:edges[src]){
              cache[src]=max(cache[src],longest(next)+1);
         }
         return cache[src];
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        edges.resize(n);
        cache.resize(n);
        unordered_map<string,int> mp;
        for(int i=0 ;i<words.size() ;i++){
             mp[words[i]]=i;
        } 
        for(int i=0; i<words.size() ;i++){
              string word=words[i];
              for(int j=0; j<word.size() ;j++){
                   string new_word = word.substr(0,j) + word.substr(j+1);
                   if(!mp.count(new_word))continue;
                   edges[mp[new_word]].push_back(i);
              }
        }
        int ans=0;
        for(int i=0; i<n ; i++){
             ans=max(ans,longest(i));
        }
        return ans;
        
    }
};
