/*
Logic explained :

Note: The tricky part is that , question has asked for combinations not permutations
If only permutations were asked , we could have simply done dp[i]=dp[i-3]+dp[i-5]+dp[i-10] , as it does not care about the duplicate sets .

Now to avoid that,
1) first mark all values which can be made by moving 3 .
eg if n=8 . all values that can be made using only 3 coins are multiple of 3 .
Technically we write it as dp[i]=d[i]+dp[i-3];
2)Now moves using 3 are done , mark all moves by moving 5 , This gives us all combinations that can be made using only 3 and 5
Technically we write it as dp[i]=dp[i]+dp[i-5]
3)Now moves using 3 and 5 are done , mark all moves by moving 10 , This gives us all combinations that can be made using 3 , 5 and 10(note that we would never come across duplicated in such a case)
Technically we write it as dp[i]=dp[i]+dp[i-10]

Link : https://practice.geeksforgeeks.org/problems/reach-a-given-score/0

*/


#include<bits/stdc++.h>
using namespace std;


int dp[1000];



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=3; i<=n ; i++)
        dp[i]+=dp[i-3];

        for(int i=5; i<=n ; i++)
        dp[i]+=dp[i-5];

         for(int i=10; i<=n ; i++)
        dp[i]+=dp[i-10];


        cout<<dp[n]<<endl;
    }
}
