#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &item_wt,vector<int> &item_val,int bag_space,int index,vector<vector<int>> &dp)
{
    if(index == 0)
    {
        if(item_wt[0] <= bag_space)
        {
            return item_val[0];
        }
        else
        {
            return 0;
        }
    }
    // step 3 
    if(dp[index][bag_space] != -1)
      return dp[index][bag_space];

    int inc=0,exc=0;

    exc = knapsack(item_wt,item_val,bag_space,index-1,dp) + 0;
    if(item_wt[index] <= bag_space)
    {
        inc = item_val[index]+knapsack(item_wt,item_val,bag_space-item_wt[index],index-1,dp);
    }

    // step 2
    dp[index][bag_space] = max(inc,exc);

    return dp[index][bag_space];

}

int main()
{
    int bag_space;
    cout<<"enter the total space of thief bag "<<endl;
    cin>>bag_space;

    vector<int> item_wt = {3,2,5};
    int index = item_wt.size();

    vector<int> item_val = {30,40,60};

    // step 1--->2d dp array --->due to 2 values are changing 
    vector<vector<int> > dp(index, vector<int>(bag_space+1,-1));

    cout<<knapsack(item_wt,item_val,bag_space,index-1,dp)<<endl;

    return 0;
}