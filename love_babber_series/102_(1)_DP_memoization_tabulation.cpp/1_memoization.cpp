// FIBONACCI SERIES            ----------->

// feature\Algorithm                 Recursion                    Dynamic Programming

// Coding Logic                  Base Case + Pattern                 Base Case + Pattern
// Store Intermediate Result?            No                           Yes
// Procedure Plot                     Tree Like                      Linear
// O (Time Complexity)                 O(2^n)                        O(n)
// O (Space Complexity)                 O(n)                          O(n)
 

#include<iostream>
#include<vector>
using namespace std;


int fibo(int n,vector<int> &dp)
{
    if(n==0 || n==1)
    {
        return n;
    }
    
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);

    return dp[n];

}

int main()
{
   int n;
   cout<<"enter size of dp"<<endl;
   cin>>n;

   vector<int> dp(n+1);

   for(int i =0;i<=n;i++)
   {
      dp[i]=-1;
   }

   cout<<fibo(n,dp)<<endl;

   return 0;
}

 

 

 

 

 


 

 

 

 
