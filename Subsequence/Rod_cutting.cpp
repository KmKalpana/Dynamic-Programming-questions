//Unbounded knapsack
#include <iostream>
using namespace std;
int max(int a, int b)
 { 
     return a>b?a:b;
     }
int rodcutting(int price[], int length, int n)
{
    int dp[length+1];
     dp[0]=0;
    for(int i=1; i<=length; i++) 
    {
        int max_val=INT_MIN;
        for(int j=0; j<i; j++) 
        {
            max_val=max(max_val,price[j]+dp[i-j-1]);
            dp[i]=max_val;
        }
    }
    return dp[length];
}
int main()
{
    int price[]={4,5,1,5,3,2,5,6};
    int n=sizeof(price)/sizeof(price[0]);
    int length=2;
    cout<<rodcutting(price,length,n);
}