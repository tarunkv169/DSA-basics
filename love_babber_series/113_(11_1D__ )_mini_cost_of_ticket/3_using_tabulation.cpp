#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int> &days,vector<int> &cost_3_pass,int n,int index,vector<int> &dp)
{
    // step 2 base cases     bottom-up approach thats why nth value set as 0;
    dp[n]=0;

    for(int k=n-1;k>=0;k--)
    {
        int option1 = cost_3_pass[0] + dp[k+1];

        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int option2 = cost_3_pass[1] + dp[i];

        for(i=k;i<n && days[i]<days[k]+30;i++);
        int option3 = cost_3_pass[2] + dp[i];

        dp[k]=min(option1,min(option2,option3));
    }

    return dp[0];
}

int min_cost(vector<int> days,vector<int> cost_3_pass)
{
    int n = days.size();

    // step 1
    vector<int> dp(n+1,INT_MAX);

    int ans = solve(days,cost_3_pass,n,0,dp);

    return ans;
}

int main()
{
    vector<int> days={1,3,4,5,7,8,10};
    vector<int> cost_3_pass ={2,7,20};

    cout<<"minimum cost required to complete his tour is "<<min_cost(days,cost_3_pass)<<endl;

    return 0;
}