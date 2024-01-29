#include<iostream>
#include<vector>
using namespace std;

int min_clim_cost(vector<int> &cost)
{
   int n = cost.size();

   //step 1
   int prev1 = cost[0];
   int prev2 = cost[1];

   //step 2
   for(int i=2;i<n;i++)
   {
      int curr = min(prev1,prev2) + cost[i];

      prev1 = prev2;
      prev2 = curr;
   } 

   return min(prev2,prev1);
}

int main()
{
   vector<int> cost = {100,200,300,400,500,600,700,800,900,1000};

   cout<<"so total min_cost of climb "<<cost.size()<<" stairs is "<<min_clim_cost(cost)<<endl;

   return 0;
}