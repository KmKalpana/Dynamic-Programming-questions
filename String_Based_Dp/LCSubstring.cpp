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
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
               dp[i][j]=1+dp[i-1][j-1];
               ans=max(ans,dp[i][j]);
            }
            else
               dp[i][j]=0;
        }
    }
   cout<<ans<<endl; 
    }