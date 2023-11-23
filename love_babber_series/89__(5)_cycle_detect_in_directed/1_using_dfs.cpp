#include<iostream>
#include<vector>
using namespace std;


bool cyclic(vector<int> adjlist[],bool visited[],bool dfs_visited[],int n,int src)
{
    visited[src]=true;
    dfs_visited[src]=true;

    for(int i=0;i<adjlist[src].size();i++)
    {
        int neighbour=adjlist[src][i];
        if(!visited[neighbour])  // in visited we have to check neighbour (unfortunately I put i in this)
        {
            if(cyclic(adjlist,visited,dfs_visited,n,i))
            {
                return true;
            }
        }
        else if(dfs_visited[neighbour])
        {
            return true;
        }
    }

    dfs_visited[src]=false;
    return false;
}

int main()
{
    cout<<"enter the no. of nodes "<<endl;
    int n;
    cin>>n;

    cout<<"enter the no. of edges "<<endl;
    int e;
    cin>>e;

    vector<int> adjlist[n+1];
    cout<<"enter the edges "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        //due to directed
        adjlist[u].push_back(v);

    }
    
    cout<<"adjaceny list is "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }



    bool visited[n]={false};
    bool dfs_visited[n]={false};            // need of dfs_visited to tell backtracking occur or not

    bool track_cyclic=false;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(cyclic(adjlist,visited,dfs_visited,n,i))
            {
                cout<<"yes it is cyclic "<<endl;
                track_cyclic=true;
                break;
            }
        }
    }

     if(!track_cyclic)
   {
      cout<<"no, its not cyclic"<<endl;
         
   }

   return 0;

}