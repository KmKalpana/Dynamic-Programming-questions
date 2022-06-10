#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int LCSubstring(string &s, string &t, int n, int m, vector<vector<int>>&dp,int ans)
{
       if(n==0||m==0)
       {
       return ans;
       }
       //if(dp[n][m]!=-1)
       // return dp[n][m];
       int lcs=ans;
       if(s[n-1] == t[m-1])
       {
           lcs=LCSubstring(s,t,n-1,m-1,dp,ans+1);
       }
       int lcs1=LCSubstring(s,t,n-1,m,dp,0);
       int lcs2=LCSubstring(s,t,n,m-1,dp,0);
       return max({lcs,lcs1,lcs2});

}
int main()
{
    string s="abcde";
    string t="decab";
   int n=s.length();
  int m= t.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
    int ans=0;
    //Memoization method.
    ans=LCSubstring(s,t,n,m,dp,ans);
    //Tabular Method
   /* for(int i=1; i<=n; i++)
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
    }*/ 
   cout<<ans<<endl; 
    }