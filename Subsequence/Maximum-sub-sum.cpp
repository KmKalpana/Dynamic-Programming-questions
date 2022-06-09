//Maximum subsequence sum such that no three are consecutive
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int subsequenceSum(int ind, vector<int>&arr, vector<vector<int>>&dp,int counter)
{
    if(ind<0)
    {
        return 0;
    }
    if(counter>=2)
    return 0;
    if(dp[ind][counter]!=-1)return dp[ind][counter];
    int take=0;
    
     int not_Take=subsequenceSum(ind-1,arr,dp,0);
    
     take=max(arr[ind]+subsequenceSum(ind-1,arr,dp,counter+1),arr[ind]+subsequenceSum(ind-2,arr,dp,0));
     return dp[ind][counter] = max(not_Take,take);
}
int main()
{
    vector<int>arr={3000, 2000, 1000, 3, 10,14,12,13};
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(3,-1));
    int counter=0;
    cout<<"Maximum sum is: "<<subsequenceSum(n-1,arr,dp,counter)<<endl;
}