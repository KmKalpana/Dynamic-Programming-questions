#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int knapsack(int W, int wt[], int p[], int n)
 {
     vector <int>dp(W+1);
for(int i=0; i<=W; i++)
    {
      for(int j=0; j<n; j++)
      {
           if(wt[j]<=i)
          {
             dp[i]=max(p[j]+dp[i-wt[j]],dp[i]);
          }
      }
    }
  return dp[W];
}
int main()
{
    int wt[] = {2,3,1,4};
    int profit[]={9,6,8,10};
    int W=2;
    int n=sizeof(wt)/sizeof(wt[0]);
    cout<<"Total weight of knapsack is: "<<knapsack(W,wt,profit,n);

}