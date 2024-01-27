// Ninja is given an array of integers that contain numbers in random order. He needs to write a
// program to find and return the number which occurs the maximum times in the given input. He
// needs your help to solve this problem.

// If two or more elements contend fdr the maximum frequency. return the element which occurs
// in the array first .e. whose index is lowest.


#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {1,1,1,2,3,1,2,3,3,3};
    unordered_map<int,int> un;
    
    int maxfreq = 1;
    for(int i=0;i<arr.size();i++)
    {
         un[arr[i]]++;
         maxfreq=max(maxfreq,un[arr[i]]);
    }
    
    int ans;
    for(int i=0;i<un.size();i++)
    {
        if(maxfreq==un[arr[i]]){
           ans = arr[i];
        }
    }

    cout<<ans;
}