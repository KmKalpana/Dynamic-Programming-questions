//Bounded Knapsack
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int knapsack(int W, int wt[], int p[], int n)
 {
     vector <vector<int> >dp(n+1,vector<int>(W+1));
for(int i=0; i<=n; i++)
    {
      for(int w=0; w<=W; w++)
      {
          if(i==0||w==0)
          {
              dp[i][w]=0;
          }
          else if(wt[i-1]<=w)
          {
             dp[i][w]=max((p[i-1]+dp[i-1][w-wt[i-1]]),dp[i-1][w]);
          }
          else
          {
              dp[i][w]=dp[i-1][w];
          }
      }
    }
  return dp[n][W];
}
int main()
{
    int wt[] = {4,26,3,4};
    int profit[]={1,2,3,4};
    int W=33;
    int n=sizeof(wt)/sizeof(wt[0]);
    cout<<"Total weight of knapsack is: "<<knapsack(W,wt,profit,n);

}