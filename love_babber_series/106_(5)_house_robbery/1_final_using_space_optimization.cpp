// Mr. x is a professional robber planning to rob houses along a street. Each house has a certain
// amount of money hidden. All houses along this street are arranged in a circle. That means the
// first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system
// connected, and it will automatically contact the police if two adjacent houses were broken into
// on the same night.
// You are given an array/list of non-negative integers 'ARR' representing the amount of money
// of each house. Your task is to return the maximum amount of money Mr. x can robb tonight without alerting police

#include<iostream>
#include<vector>
using namespace std;

int max_sum_Nadj(vector<int> &arr)
{
   int n=arr.size();
   // step 1;
   int prev1 = arr[0];
   int prev2 = max(arr[0],arr[1]);

   int inc;
   int exc;
   int curr;
   for(int i=2;i<n;i++)
   {
       inc = prev1 + arr[i];
       exc = prev2 + 0;
       
       curr = max(inc,exc);

       prev1 = prev2;
       prev2 = curr;
   }

   return curr;

}


int main()
{
    vector<int> house_money = {200,300,400,500,600,700};
    int n = house_money.size();

    vector<int> first_arr;
    vector<int> second_arr;

    if(n==1)
      return house_money[0];

    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
           first_arr.push_back(house_money[i]);
        }

        if(i!=0)
        {
           second_arr.push_back(house_money[i]);
        }
    }

    int sum1 = max_sum_Nadj(first_arr);
    int sum2 = max_sum_Nadj(second_arr);

    int final_sum = max(sum1,sum2);

    cout<<" maximum amount of money Mr. x can robb  "<<final_sum<<endl;

    return 0;
}