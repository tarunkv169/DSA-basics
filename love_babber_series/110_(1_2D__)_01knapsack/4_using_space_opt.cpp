#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &item_wt, vector<int> &item_val, int bag_space, int index)
{
    // step 1
    vector<int> prev(bag_space + 1, 0);
    vector<int> curr(bag_space + 1, 0);
    // step 2
    for (int i = item_wt[0]; i <= bag_space; i++)
    {
        if (i <= bag_space)
        {
            prev[i] = item_val[0];
        }
        else
        {
            prev[i] = 0;
        }
    }

    // step 3
    for (int i = 1; i <= index; i++)
    {
        for (int j = 0; j <= bag_space; j++)
        {
            int inc = 0, exc = 0;
            exc = prev[j] + 0;

            if (item_wt[i] <= j)
            {
                inc = item_val[i] + prev[j - item_wt[i]];
            }

            curr[j] = max(inc, exc);
        }
        prev = curr;
    }

    return prev[bag_space];
}

int main()
{
    int bag_space;
    cout << "Enter the total space of thief bag: " << endl;
    cin >> bag_space;

    vector<int> item_wt = {3, 2, 5};
    int index = item_wt.size();

    vector<int> item_val = {30, 40, 60};

    cout << "Maximum value that can be obtained: " << knapsack(item_wt, item_val, bag_space, index - 1) << endl;

    return 0;
}
