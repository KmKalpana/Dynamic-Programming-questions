#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s="abcde";
    string t="decab";
   int n=s.length();
   int m= t.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
    vector<int>prev(m+1,0),curi(m+1,0);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
               dp[i][j]=1+dp[i-1][j-1];
            }
            else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;  
    int length=dp[n][m];
      string ans="";
      for(int i=0; i<length; i++)
      {
          ans+="k";
      }
      length-=1;
      int i=n, j=m; 
      while(i>0 && j>0)
      {
          if(s[i-1]==t[j-1])
          {
              ans[length]=s[i-1];
              i--, j--;
              length--;
          }
          else if(dp[i-1][j]>dp[i][j-1])
          {
              i--;
          }
          else
          {
              j--;
          }
      }
      cout<<"Longest Common Subsequence is: "<<ans<<endl;
    }