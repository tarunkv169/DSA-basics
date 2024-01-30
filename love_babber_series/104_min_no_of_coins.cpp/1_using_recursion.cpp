#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


int solve(vector<int> &coins,int n)
{
    if(n == 0)
      return 0;
    
    if(n < 0)
      return INT_MAX;

    int mini = INT_MAX;

    for(int i=0;i<coins.size();i++)
    {
        int ans = solve(coins,n-coins[i]);

        if(ans != INT_MAX)
        {
            mini = min(mini,1+ans);
        }
    }

    return mini;
}


int min_no_coins(vector<int> &coins,int n)
{
    int ans = solve(coins,n);

    if(ans==INT_MAX)
    {
        return -1;
    }
}

int main()
{
    vector<int> coins = {1,2,3};
    int n;
    cout<<"enter the amount u need "<<endl;
    cin>>n;

    cout<<min_no_coins(coins,n);

    return 0;
}