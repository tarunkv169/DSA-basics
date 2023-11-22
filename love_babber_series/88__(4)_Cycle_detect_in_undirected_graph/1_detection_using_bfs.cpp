#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool cyclic(vector<int> adjlist[],bool visited[],int n,int src)
{
    
    visited[src]=true;
    int parent[n];
    parent[src]=-1;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front=q.front();
        q.pop();

        for(int i=0;i<adjlist[front].size();i++)
        {
            if(visited[adjlist[front][i]]==true && adjlist[front][i]!=parent[front])
            {
                return true;
            }
            else
            {
                visited[adjlist[front][i]]=true;
                parent[adjlist[front][i]]=front;
                q.push(adjlist[front][i]);
            }
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