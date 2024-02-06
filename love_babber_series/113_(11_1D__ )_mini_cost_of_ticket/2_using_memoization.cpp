#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &days,vector<int> &cost_3_pass,int n,int index,vector<int> &dp)
{
    if(index >= n)
       return 0;

    // step 3
    if(dp[index]!=-1)
       return dp[index];

    // step 2
    int option1 = cost_3_pass[0] + solve(days,cost_3_pass,n,index+1,dp);

    int i;
    for(i=index; i<n && days[i] < days[index]+7; i++);
    int option2= cost_3_pass[1] + solve(days,cost_3_pass,n,i,dp);

    for(i=index; i<n && days[i] < days[index]+30; i++);
    int option3 = cost_3_pass[2] + solve(days,cost_3_pass,n,i,dp);
    
    dp[index] = min(option1,min(option2,option3));

    return dp[index];
}

int min_cost(vector<int> days,vector<int> cost_3_pass)
{
    int n = days.size();

    // step 1
    vector<int> dp(n+1,-1);

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