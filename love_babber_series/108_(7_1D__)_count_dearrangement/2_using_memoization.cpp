#include<iostream>
#include<vector>
using namespace std;

int count_dearrage(vector<int> &arr,int n,vector<int> &dp)
{
    if(n==1)
      return 0;
    if(n==2)
      return 1;
    
    // step 3
    if(dp[n]!=-1)
      return dp[n];
     
    // step 2
    dp[n] = (n-1)*(count_dearrage(arr,n-1,dp)+count_dearrage(arr,n-2,dp));

    return dp[n];

    
}

int main()
{
    vector<int> arr = {0,1,2,3};
    int n=arr.size();
    // step 1
    vector<int> dp(n+1,-1);

    cout<<"total no. of dearrangements possible "<<count_dearrage(arr,n,dp);

}