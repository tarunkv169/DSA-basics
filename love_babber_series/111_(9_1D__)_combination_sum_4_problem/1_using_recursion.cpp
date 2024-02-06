// You are given an array of distinct integers and you have to tell how many different ways of
//  selecting the elements from the array are there such that the sum of chosen elements is equal
//  to the target number tar.
//  Note: Two ways are considered the same if for every index the contents of both the ways are
//  equal example way1=[1.2.3.1] and way2= [1.2,3,1] both way1 and way 2 are the same.
//  But if way1 =[1.2,3,4) and way2= (4,3,2,1) then both ways are different.
//  Input Is Given Such That The Answer Will Fit In A 32-bit Integer.
//  For Example:
// If N=3 and tar - 5 and array elements are (1,2,5) then the number of
//  possible ways of making sum are:
//  (1,1,1,1,1)
//  (1,1,1,2)
//  (1,2,1,1)
//  (2,1,1,1)
//  (1,1,2,1)
//  (2,2,1)
//  (1,2,2)
//  (2.1.2)
//  (5)
// the output will be 9.



#include<iostream>
#include<vector>
using namespace std;

int total_combi(vector<int> &arr,int target)
{
    if(target == 0)
       return 1;
    if(target < 0)
       return 0;
    
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        int n = total_combi(arr,target-arr[i]);
        sum=sum+n;
    }

    return sum;
}

int main()
{
    vector<int> arr={1,2,5};
    int target;
    cout<<"enter the target ele "<<endl;
    cin>>target;

    cout<<"total ways of combinations "<<total_combi(arr,target)<<endl;

    return 0;
}