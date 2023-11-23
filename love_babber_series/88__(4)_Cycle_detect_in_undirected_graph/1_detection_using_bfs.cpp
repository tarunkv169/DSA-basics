// nothing special we do we apply bfs (in which we just maintain parent array(in which index is child and value is parent) to keep track of node with its parent node)
// with help of parent array we apply condi---- if previous node is not parent of next node than it is cyclic


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
        int current_node=q.front();
        q.pop();

        for(int i=0 ; i<adjlist[current_node].size() ; i++) //jo current_node ke adjacent nodes hain(jo ki adjlist mein hamne store kiye the like 1->2,4,5) unko iterate kr rhe hain
        {
            //adjlist[current_node][i]---we check first adjacent node(of our current_node) is it visited
            if(visited[adjlist[current_node][i]]==true && adjlist[current_node][i]!=parent[current_node])
            {
                return true;
            }
            else
            {
                visited[adjlist[current_node][i]]=true;
                parent[adjlist[current_node][i]]=current_node;
                q.push(adjlist[current_node][i]);
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