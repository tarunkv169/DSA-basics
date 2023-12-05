// same as bfs code just in this ----1. we dont need to maintain queue
//                                   2. need of recursive call


#include<iostream>
#include<vector>
using namespace std;


void dfs(vector<int> adjlist[],bool visited[],int firstnode)
{
    // VT P RC
    visited[firstnode]=true;
    cout<<firstnode<<" ";

    for(int i=0;i<adjlist[firstnode].size();i++)
    {
        if(!visited[adjlist[firstnode][i]])
        {
            dfs(adjlist,visited,adjlist[firstnode][i]);
        }
    }
}


int main()
{
    cout<<"enter the no. of nodes/vertices"<<endl;
    int n;
    cin>>n;

    cout<<"enter the no. of edges "<<endl;
    int e;
    cin>>e;

    vector<int> adjlist[n];
    
    cout<<"enter 0 for undirected and 1 for directed"<<endl;
    int direction;
    cin>>direction;
    
    cout<<"enter the edges "<<endl;
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
    
    cout<<"printing the adjlist"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<endl;
        }
        cout<<endl;
    }


    bool visited[n]={false};

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(adjlist,visited,0);
        }
    }

}
