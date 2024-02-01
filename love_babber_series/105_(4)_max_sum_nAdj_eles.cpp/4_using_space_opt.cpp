#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &arr,int n)
{
    //step 1
    int prev1 = arr[0];
    int prev2 = max(arr[0],arr[1]);

    int curr = 0;

    for(int i=2;i<n;i++)
    {
        int inc = prev1 + arr[i];
        int exc = prev2 + 0;

        curr = max(inc,exc);

        prev1 = prev2; 
        prev2 = curr; 
    }

    return curr;
}

int main()
{
    vector<int> arr = {9, 9, 8, 2};
    int n = arr.size();
    int ans = solve(arr, n - 1);  // Subtract 1 when passing n

    cout << "max sum of Non-Adj eles = " << ans << endl;

    return 0;
}