// Ninja Is Willing To Take Some Time of From His Training And Planning A Year-long Tour.
// You Are Given A DAYS Array Consisting Of 'N' Days When Ninjas Will Be Traveling During The
// Year. Each Day Is An Integer Between 1 To 365 (Both Inclusive).
// Train Tickets Are Sold In Three Different Ways:

// A 1-day pass is sold for 'COST' [0] coins,
// A 7-day pass is sold for 'COST' [1] coins, and
// A 30-day pass is sold for 'COST' [2] coins.
// The passes allow for many days of consecutive travel.

// Your Task Is To Help The Ninja To Find The Minimum Number Of Coins Required To Complete His
// Tour.
//  For Example,
//    If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4,
//    5, 6, 7, and 8.



#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &days,vector<int> &cost_3_pass,int n,int index)
{
    if(index>=n)
       return 0;
    
    // 1-day pass----simply(i. add cost of 1-day_pass) (ii. increament index by 1)
    int option1 = cost_3_pass[0] + solve(days,cost_3_pass,n,index+1);

    // 7-day pass----simply(i. add cost of 7-day_pass) (ii. increament index by increament of 7days...like let we are at (day = 3) then then index will go upto (day = 3+7=10))
    int i;
    for(i = index ; i<n && days[i] < days[index]+7 ; i++);
    int option2 = cost_3_pass[1] + solve(days,cost_3_pass,n,i);

    // 30-day pass----similarly
    for(i = index ; i<n && days[i] < days[index]+30 ; i++);
    int option3 = cost_3_pass[2] + solve(days,cost_3_pass,n,i);



    int ans = min(option1,min(option2,option3));

    return ans;
}


int min_cost(vector<int> &days,vector<int> &cost_3_pass)
{
    int n = days.size();

    int ans = solve(days,cost_3_pass,n,0);

    return ans;
}

int main()
{
    vector<int> days={1,3,4,5,7,8,10};
    vector<int> cost_3_pass ={2,7,20};

    cout<<"minimum cost required to complete his tour is "<<min_cost(days,cost_3_pass)<<endl;

    return 0;
}