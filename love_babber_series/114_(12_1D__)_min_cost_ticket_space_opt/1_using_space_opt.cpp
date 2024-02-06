#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

int solve(vector<int> &days,vector<int> &cost_3_pass)
{
    int ans = 0;
    
    // step 1 make queue of constant size for---------- S.C=O(1)
    queue<pair<int,int> >  month;
    queue<pair<int,int> > week;

    for(int day:days)
    {
        // step 2 remove(pop) expired days(which we tour at back like 1-day pass when we are at 2 days then 1st day is expired day)
        while(!month.empty() && month.front().first+30 <= day)
        {
            month.pop();
        }
        while(!week.empty() && week.front().first+7 <= day)
        {
            week.pop();
        }

        // step 3 add(push) cost for current day
        week.push(make_pair(day,ans+cost_3_pass[1]));
        month.push(make_pair(day,ans+cost_3_pass[2]));

        // step 4 update ans
        ans = min(ans + cost_3_pass[0],min(week.front().second,month.front().second));

    }

    return ans;
}

int min_cost(vector<int> days,vector<int> cost_3_pass)
{
    int n = days.size();

    int ans = solve(days,cost_3_pass);

    return ans;
}

int main()
{
    vector<int> days={1,3,4,5,7,8,10};
    vector<int> cost_3_pass ={2,7,20};

    cout<<"minimum cost required to complete his tour is "<<min_cost(days,cost_3_pass)<<endl;

    return 0;
}