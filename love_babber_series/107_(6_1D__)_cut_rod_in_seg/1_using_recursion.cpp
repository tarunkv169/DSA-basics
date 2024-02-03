// You are given an integer 'N' denoting the length of the rod.
//  You need to determine the maximum number of segments
// you can make of this rod provided that each segment
//  should be of the length 'X'. 'Y'. or 'Z'.



#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int> seg,int l)
{
    if(l==0)
      return 0;
    if(l<0)
      return INT_MIN;

    int maxi = INT_MIN;
    for(int i=0;i<seg.size();i++)
    {
        int ans = solve(seg,l-seg[i]);

        if(ans!=INT_MIN)
        {
            maxi = max(maxi,ans+1);
        }
    }

    return maxi;
}


int rod_cut(vector<int> seg,int l)
{
    int ans = solve(seg,l);

    if(ans<0)
      return -1;
    else
      return ans;
}

int main()
{
    int l;
    cout<<"enter the rod length "<<endl;
    cin>>l;

    vector<int> seg = {3,3,3};

    cout<<rod_cut(seg,l)<<endl;

    return 0;    
}

