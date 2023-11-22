#include<iostream>
#include<vector>
using namespace std;

bool cyclic(vector<int> adjlist[],bool visited[],int n,int src)
{
    visited[src]=true;
    int parent[n];
    parent[src]=-1;

    for(int i=0;i<adjlist[src].size();i++)
    {
        if(visited[adjlist[src][i]==true && adjlist[src][i]!=parent[src]])
        {
            return true;
        }
        else
        {
            cyclic(adjlist,visited,n,adjlist[src][i]);
        }
    }

    return false;
}

int main()
{
    cout<<"enter the total no. of nodes "<<endl;
    int n;
    cin>>n;

    cout<<"enter the total no. of edges "<<endl;
    int e;
    cin>>e;

    vector<int> adjlist[n];
    bool visited[n]={false};

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        
    }


   bool track_cyclic=false;
   for(int i=0;i<n;i++)
   {
      if(!visited[i])
      {
         if(cyclic(adjlist,visited,n,i))
         {
           cout<<"yes,it is cylcic"<<endl;
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