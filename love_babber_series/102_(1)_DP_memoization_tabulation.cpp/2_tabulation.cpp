#include<iostream>
#include<vector>
using namespace std;

int fibo(int n,vector<int> &dp)
{
    if(n==0 || n==1)
    {
        return n;
    }
    
    // we values of dp[0] and dp[1] with these two we find dp[2] ,then iteratively we will find all dp values 
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int main()
{
    int n;
    cout<<"enter the size of dp or whose fibo no u want to find"<<endl;
    cin>>n;

    vector<int> dp(n+1);

    dp[0]=0;
    dp[1]=1;

    cout<<fibo(n,dp)<<endl;
}