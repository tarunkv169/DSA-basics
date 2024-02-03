// Ninja has given a fence. and he gave a task to paint this fence. The fence has 'N' posts, and
// Ninja has "K" colors. Ninja wants to paint the fence so that not more than two adjacent posts
// have the same color.
// Ninja wonders how many ways are there to do the above task, so he asked for your help.
// Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo
//  1019 +7.
//  Example:
//    Input: 'N' 3, *K = 2
//    Output: 6
   
#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;

int add(int a,int b)
{
    return ((a%mod) + (b%mod))%mod;
}

int mul(int a,int b)
{
    return ((a%mod) * (b%mod))%mod;
}


int ways(int k,int n)
{
    if(n==1)
      return k;        //n(1) = k ways to color
    if(n==2)
      return add(k,mul(k,k-1));  //n(2) = k + k(k-1) ways to color
    
    int ans = mul(k-1,add(ways(k,n-2) , ways(k,n-1)));

    return ans;
}

int main()
{
    int colors,posts;
    cout<<"enter the no. of colours and fence_posts "<<endl;
    cin>>colors>>posts;

    cout<<"the number of ways Ninja can paint the fence   "<<ways(colors,posts)<<endl;

    return 0;
}