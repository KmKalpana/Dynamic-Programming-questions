//Bounded Knapsack
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={2,3,7,8,11};
    int n=5;
    int sum=18;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j && i<j)  
            {
                if(a[i]+a[j]==sum)
                {
                 v.push_back(a[i]);
                 v.push_back(a[j]);
                 break;
                }
            }
        }
    }
 for(int i=0; i<v.size(); i++) 
 {
     cout<<v[i]<<" ";
 }
}