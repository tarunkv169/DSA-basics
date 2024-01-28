#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the index at which u want to find out fibonacci no"<<endl;
    cin>>n;

    int prev1 = 0;
    int prev2 = 1;

    int curr;
    for(int i=2;i<=n;i++)
    {
       curr = prev1 + prev2;
       prev1 = prev2;
       prev2 = curr;
    }

    cout<<curr<<endl;


    return 0;
}