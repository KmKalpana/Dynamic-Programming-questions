#include <iostream>
using namespace std;
int max(int a, int b)
 { 
     return a>b?a:b;
     }
int coin_max(int coins[], int amt, int n)
{
    int dp[n+1][amt+1];
    for(int j=0; j<=amt; j++)
    {
        dp[0][j]=0;
    }
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=1;
    }
    for(int i=1; i<=n; i++) 
    {
        for(int j=1; j<=amt; j++) 
        {
          if(coins[i-1]>j)
         dp[i][j]=dp[i-1][j];
         else
         dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
        }
    }
    return dp[n][amt];
}
int main()
{
    int coins[]={1,2,3};
    int n=sizeof(coins)/sizeof(coins[0]);
    int amt=5;
    cout<<coin_max(coins,amt,n);
}