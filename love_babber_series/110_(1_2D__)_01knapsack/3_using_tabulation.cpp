#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &item_wt,vector<int> &item_val,int bag_space,int index,vector<vector<int>> &dp)
{

    // step 2 
    for(int i = item_wt[0];i<=bag_space;i++)
    {
        if(i<=bag_space)
        {
           dp[0][i]=item_val[0];
        }
        else{
            dp[0][i]=0;
        }
    }

    // step 3
    
    for(int i=1;i<index;i++)
    {
        for(int j=0;j<=bag_space;j++)
        {
            int inc=0,exc=0;
            exc = dp[i-1][j] + 0;

            if(item_wt[i] <= bag_space)
            {
                inc = item_val[i] + dp[i-1][j-item_wt[i]];
            }
            dp[i][j] = max(inc,exc);
        }
    }


    return dp[index-1][bag_space];

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
    vector<vector<int> > dp(index, vector<int>(bag_space+1));

    cout<<knapsack(item_wt,item_val,bag_space,index-1,dp)<<endl;

    return 0;
}