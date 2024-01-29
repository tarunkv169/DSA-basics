#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int> &cost,int n,vector<int> &dp)
{
   if(n == 0)
   {
      return cost[0];
   }
   
   if(n == 1)
   {
      return cost[1];
   }

   //step 3 
   if(dp[n]!=-1)
      return dp[n];
   
   //step 2
   dp[n] = min(solve(cost,n-1,dp),solve(cost,n-2,dp)) + cost[n];

   return dp[n];

}

int min_clim_cost(vector<int> &cost)
{
    int n = cost.size();
    //step 1
    vector<int> dp(n+1,-1);

    int total_cost = min(solve(cost,n-1,dp),solve(cost,n-2,dp));

    return total_cost;
}

int main()
{
    vector<int> cost ={100,200,300,400,500,600,700,800,900,1000};

    cout<<"so total min_cost of climb "<<cost.size()<<" stairs is "<<min_clim_cost(cost)<<endl;

    return 0;
}