#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &arr, int n, vector<int> &dp) {
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]); // Handle the base case for n = 1 separately

    for (int i = 2; i <= n; i++) {
        int inc = dp[i - 2] + arr[i];
        int exc = dp[i - 1];

        dp[i] = max(inc, exc);
    }

    return dp[n];
}

int main() {
    vector<int> arr = {9, 9, 8, 2};
    int n = arr.size();
    // Step 1
    vector<int> dp(n, 0);
    int ans = solve(arr, n - 1, dp);  // Subtract 1 when passing n

    cout << "max sum of Non-Adj eles = " << ans << endl;

    return 0;
}
