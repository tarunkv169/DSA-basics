#include<iostream>
#include<vector>
using namespace std;

int min_clim_cost(vector<int> &cost)
{
    int n = cost.size();

    // step 1
    vector<int> dp(n+1);

    // step 2
    dp[0]=cost[0];
    dp[1]=cost[1];

    // step 3
    for(int i=2;i<n;i++)
    {   // case 2 -- when we climbing in between or less than nth step so it include cost of step also from where we proceed---------  ( f(n-1) = min(f(n-2),f(n-3)) + cost[n-1])
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }

   // case 1 --when we reach the nth stair so ------- ( f(n) = min(f(n-1), f(n-2))   )
    return min(dp[n-1],dp[n-2]);

}

int main()
{
   vector<int> cost = {100,200,300,400,500,600,700,800,900,1000};

   cout<<"so total min_cost of climb "<<cost.size()<<" stairs is "<<min_clim_cost(cost)<<endl;

   return 0;
}