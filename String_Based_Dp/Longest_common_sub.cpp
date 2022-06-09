#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*   Recursion Approach.
int helper(int n, int m, string &s, string &t)
{
    if(n==0 || m==0)
        return 0;
    if(s[n-1]==t[m-1])
     return 1+helper(n-1,m-1,s,t);
    else
    return max(helper(n-1,m,s,t),helper(n,m-1,s,t));
}
*/
int main()
{
    string s="abcde";
    string t="decab";
   int n=s.length();
  int m= t.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
	//return helper(n,m,s,t,dp);
    vector<int>prev(m+1,0),curi(m+1,0);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
               dp[i][j]=1+dp[i-1][j-1];
               // curi[j]=1+prev[j-1];
            }
            else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                //curi[j]=max(prev[j],curi[j-1]);
        }
       // prev=curi;
    }
   // return dp[n][m];
    cout<<dp[n][m]<<endl;  
    }