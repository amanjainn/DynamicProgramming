class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        int mod=1e9+7;
        int a=0, b=0,cc=0;
        for(char c : s){
             if(c=='a'){
                 a=(2 * a)%mod  +  1;
                 a=a%mod;
             }
             if(c=='b'){
                  b= (2 * b)%mod  +  a %mod;
                  b=b%mod;
             }
             if(c=='c'){
       
                 cc=(2*cc)%mod +  b%mod;
                 cc=cc%mod;
              
             }
        }
       return cc;
    }
};
