


/*
 u can try 
 enter the no. of nodes
6
enter the no. of edges
9
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
4 5 -2

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout<<"enter the no. of nodes"<<endl;
    int n;
    cin>>n;

    cout<<"enter the no. of edges "<<endl;
    int e;
    cin>>e;

    vector<vector<int>> adjlist[n];  // vector list ko v vector bna diya so that no need to do vector<int> adjlist[n]
    for(int i=0;i<e;i++)
    { 
        int u,v,w;
        cin>>u>>v>>w;
        
        adjlist[u].push_back({v,w});
        
    }

    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto& edge : adjlist[i])
        {
            cout<<"["<<edge[0]<<" "<<edge[1]<<"]";
        }
        cout<<endl;
    }
}









