#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &arr,int n)
{  
    if(n<0)
       return 0;
    
    if(n==0)
       return arr[0];

    int inc = solve(arr,n-2) + arr[n];
    int exc = solve(arr,n-1) + 0;
    
    int max_sum = max(inc,exc);
    return max_sum;

}

int main()
{
    vector<int> arr={9,9,8,2};

    int n =arr.size();

    int ans = solve(arr,n-1);

    cout<<"max sum of Non-Adj eles "<<ans<<endl;

    return 0;

}