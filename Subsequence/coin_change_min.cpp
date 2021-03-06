//Unbounded Knapsack
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coin_min(int coins[], int amt, int n)
{
    int dp[n+1][amt+1];
    for(int j=0; j<=amt; j++)
    {
        dp[0][j]=INT_MAX;
    }
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=0;
    }
    for(int i=1; i<=n; i++) 
    {
        for(int j=1; j<=amt; j++) 
        {
     if(coins[i-1]>j)
         dp[i][j]=dp[i-1][j];
         else
         dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][amt]>=INT_MAX?-1:dp[n][amt];
}
int main()
{
    int coins[]={1,2,5};
    int n=sizeof(coins)/sizeof(coins[0]);
    int amt=6;
    cout<<coin_min(coins,amt,n);
}