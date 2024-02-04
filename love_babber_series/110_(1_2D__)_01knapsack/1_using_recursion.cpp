#include<iostream>
#include<vector>
using namespace std;


int knapsack(vector<int> &item_wt,vector<int> &item_val,int bag_space,int index)
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
    
    int exc,inc;

    exc = knapsack(item_wt,item_val,bag_space,index-1) + 0;   
    if(item_wt[index]<=bag_space)
    {
        inc = item_val[index] + knapsack(item_wt,item_val,bag_space-item_wt[index],index-1);
    }
    else{
        inc=0;
    }

    int ans = max(exc,inc);

    return ans;
}

int main()
{
    int space;
    cout<<"enter the total space of thief bag "<<endl;
    cin>>space;

    vector<int> item_wt = {3,2,5};
    int index = item_wt.size();

    vector<int> item_val = {30,40,60};

    cout<<knapsack(item_wt,item_val,space,index-1)<<endl;

    return 0;
}