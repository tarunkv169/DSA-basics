
// A Derangement is a permutation of 'N' elements,
//  such that no element appears in its original
//  position. For example, an instance of derangement
//  of {0. 1. 2, 3) is (2. 3, 1. 0). because 2 present at
// index 0 is not at its initial position which is 2 and
//  similarly for other elements of the sequence.
//  Given a number 'N'. find the total number of
// derangements possible of a set of 'N' elements.

#include<iostream>
#include<vector>

#define MOD 1000000007 // WHICH IS GIVEN 10^9+7
using namespace std;

int count_dearrage(vector<int> &arr,int n)
{
    // base case
    if(n == 1)   // if arr size is 1 then,there is no dearragement(n-1)=(1-1)=0
      return 0;
    if(n == 2)   // if arr size is 2 then,there is only 1 dearragement(n-1)=(2-1)=1
      return 1;

    // if arr size is n then,there is only n-1 dearragement(n-1)=(n-1) 
       // two ways/possiblities of dearragement --one-- is swap with other then both ele are fixed remaining ele left with(n-2) index to settle
       //                                         other-- is replace the other ele then one ele is fixed remaining ele left with(n-1)index to settle
    int ans = ((n-1) * ((count_dearrage(arr,n-1) + count_dearrage(arr,n-2)) % MOD)) % MOD;


    return ans;
}

int main()
{
    vector<int> arr = {0,1,2,3};
    int n=arr.size();

    cout<<"total no. of dearrangements possible "<<count_dearrage(arr,n);


}