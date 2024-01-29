// You are given an integer array cost where cost [i] is the cost of ith step on a
//  staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0. or the step with index 1.
//  Return the minimum cost to reach the top of the floor.


#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int> &cost,int n)
{
    // 1th step ---so min cost is cost of that step as we put only that step
    if(n == 0)
    {
        return cost[0];
    }

    // 1th step ---so min cost is cost of that step as we put only that step
    if(n == 1)
    {
        return cost[1];
    }
     
    // case 2 -- when we climbing in between or less than nth step so it include cost of step also from where we proceed---------  ( f(n-1) = min(f(n-2),f(n-3)) + cost[n-1])
    int ans = min(solve(cost,n-1),solve(cost,n-2)) + cost[n];

    return ans;
}

int min_clim_cost(vector<int> &cost)
{
   int n = cost.size();

   // case 1 --when we reach the nth stair so ------- ( f(n) = min(f(n-1), f(n-2))   )
   int total_cost = min(solve(cost,n-1),solve(cost,n-2));

   return total_cost;
}

int main()
{  
   vector<int> cost = {100,200,300,400,500,600,700,800,900,1000};

   cout<<"so total min_cost of climb "<<cost.size()<<" stairs is "<<min_clim_cost(cost)<<endl;

   return 0;
}

