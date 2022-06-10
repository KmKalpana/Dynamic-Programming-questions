#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) 
    {
       int maxi=nums[0];
       int mini=nums[0];
    int ans=nums[0];
       for(int i=1; i<nums.size(); i++)
       {
           int temp=maxi;
           maxi=max({nums[i],mini*nums[i],maxi*nums[i]});
           mini=min({nums[i],temp*nums[i],mini*nums[i]});
           ans=max(maxi,ans);
       }
        return ans;
    }
int main()
{
   vector<int>nums={2,3,-2,4};
   cout<<maxProduct(nums)<<endl;
}
