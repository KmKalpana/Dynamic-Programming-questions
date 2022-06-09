#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
int longestCommonSubsequence(string &s, string &t, int n, int m,vector<vector<int> >&dp)
{
  if(n==0 || m==0)
  {
      return 0;
  }
  if(dp[n][m]!=0)
  {
      return dp[n][m];
  }
  if(s[n-1]==t[m-1] && n!=m)
  {
      return dp[n][m]=1+longestCommonSubsequence(s,t,n-1,m-1,dp);
  }
  else
  return dp[n][m]=max(longestCommonSubsequence(s,t,n-1,m,dp), longestCommonSubsequence(s,t,n,m-1,dp));
}
void longestRepeatedSubsequence(string &s, string &t)
{
    int n=s.length();
    vector<vector<int> >dp(n+1,vector<int>(n+1,0));
  int len=longestCommonSubsequence(s,t,n,n,dp);
  string ans="";
  for(int i=0; i<len; i++)
  {
    ans+='k';
  }
  /*for(int i=0; i<n+1; i++)
  {
    for(int j=0; j<n+1; j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }*/
  int ind=len-1;
  int i=n, j=n;
  while(i>0 && j>0)
  {
     if(dp[i][j]==dp[i-1][j-1]+1)
     {
       ans[ind]=s[i-1];
       i--, j--;
       ind--;
     }
     else if(dp[i][j]==dp[i-1][j])
     i--;
     else
     j--;
  }
    cout<<ans<<endl;
}
int main()
{
  string s="xyz";
  longestRepeatedSubsequence(s,s);   
}
