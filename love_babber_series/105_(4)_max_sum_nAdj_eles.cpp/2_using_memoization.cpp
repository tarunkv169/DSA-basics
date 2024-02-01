#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &arr,int n,vector<int> &dp)
{
    if(n<0)
      return 0;
    
    if(n==0)
      return arr[0];
      
    // step 3;
    if(dp[n]!=-1)
      return dp[n];

    int inc =solve(arr,n-2,dp)+arr[n];
    int exc =solve(arr,n-1,dp)+0;
    // step 2;
    dp[n] = max(inc,exc);

    return dp[n];

}

int main()
{
    vector<int> arr={9,9,8,2};
    int n =arr.size();
    //step 1
    vector<int> dp(n,-1);

    int ans = solve(arr,n-1,dp);

    cout<<"max sum of Non-Adj eles = "<<ans<<endl;

    return 0;
}