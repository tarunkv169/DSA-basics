// You have been given a number of stairs. Initially, you are at the 0th stair, and you need to
//  reach the Nth stair. Each time you can either climb one step or two steps. You are
//  supposed to return the number of distinct ways in which you can climb from the 0th step
//  to Nth step.


// For each test case/query, print the number
//                                             of distinct ways to reach the
// top of stairs. Since the number can be huge, so return output modulo
// 10~9+7.
// Output for every test case will be printed in a separate line.

#include<iostream>
#include<vector>
using namespace std;

int distinct_climb(int src,int dest)
{
   if(src == dest)
   {
       return 1;
   }

   if(src > dest)
   {
     return 0;
   }

   int ans = distinct_climb(src+1,dest)+distinct_climb(src+2,dest);

   return ans;
}

int main()
{
    int n;
    cout<<"enter the nth stair "<<endl;
    cin>>n;

    cout<<distinct_climb(0,n)<<endl;
}