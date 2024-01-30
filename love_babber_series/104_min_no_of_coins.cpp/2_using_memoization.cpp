#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int> &coins,int n,vector<int> &dp)
{
    if(n == 0)
       return 0;
    
    if(n < 0)
       return INT_MAX;
    
    if(dp[n]!=-1)
       return dp[n];

    int mini = INT_MAX;

    for(int i=0;i<coins.size();i++)
    {
        int ans = solve(coins,n-coins[i],dp);

        if(ans!=INT_MAX)
        {
            mini=min(mini,1+ans);
        }

    }

    dp[n] = mini;

    return dp[n];
}

int min_no_coins(vector<int> &coins,int n)
{
    //step 1
    vector<int> dp(n+1,-1);

    int ans = solve(coins,n,dp);

    if(ans==INT_MAX)
      return -1;

    return ans;
}

int main()
{
    vector<int> coins = {1,2,5};
    int n;
    cout<<"enter the amount u want from min no of coins"<<endl;
    cin>>n;

    cout<<min_no_coins(coins,n)<<endl;
}