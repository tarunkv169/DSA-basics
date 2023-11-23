// using vector list------simply---------innext i used the class


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{  //                 step(1)----creating (adjceny vector list(not array it is vector list)) of graph
    cout<<"enter the total no. of nodes/vertices "<<endl;
    int n;
    cin>>n;
    
    cout<<"enter the total no. of edges "<<endl;
    int e;
    cin>>e;

    vector<int> adjlist[n]; //vector list
    cout<<"enter 0 for undirected graph and 1 for directed"<<endl;
    int direction;
    cin>>direction;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adjlist[u].push_back(v);
        if(direction==0)
        {
            adjlist[v].push_back(u);
        }

    }

    // printing adjlist
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }

}