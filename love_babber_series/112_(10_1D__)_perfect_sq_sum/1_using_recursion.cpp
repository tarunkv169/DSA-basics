#include<iostream>
#include<limits.h>
using namespace std;

int solve(int target)
{
    if(target == 0)
      return 0;
    if(target < 0)
      return INT_MAX;
    
    int mini = INT_MAX;
    for(int i=1;i*i<=target;i++)
    {
        int ans = solve(target-(i*i));

        if(ans!=INT_MAX)
        {
            mini=min(mini,1+ans);
        }
    }

    return mini;
}

int main()
{
    int target;
    cout<<"enter the target whose prefect sq's sum u want "<<endl;
    cin>>target;

    cout<<"the minimum no. of perfect sq's are "<<solve(target)<<endl;
}