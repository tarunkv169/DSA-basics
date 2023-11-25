// nothing special we do we apply bfs (in which we just maintain parent array(in which index is child and value is parent) to keep track of node with its parent node)



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<int> adjlist[],bool visited[],int n,int src)
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

        for(int i=0 ; i<adjlist[current_node].size() ; i++) 
        {
            
            if(!visited[adjlist[current_node][i]])
            {
                visited[adjlist[current_node][i]]=true;
                parent[adjlist[current_node][i]]=current_node;
                q.push(adjlist[current_node][i]);
            }
        }

    }

     
    vector<int> ans;
    int current = n;  
    ans.push_back(current);
    while (current != src) {
        current = parent[current];
        ans.push_back(current);
    }

    for (int i = ans.size() - 2; i >= 0; i--) {  // Fix: Change the loop condition and print statement
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main()
{
    cout<<"enter the total no. of nodes "<<endl;
    int n;
    cin>>n;

    cout<<"enter the total no. of edges "<<endl;
    int e;
    cin>>e;

    vector<int> adjlist[n+1];
    bool visited[n]={false};

    cout << "Enter the pairs of edges (u and v):" << endl;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        
    }

    // printing adjlist
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }


   for(int i=0;i<n;i++)
   {
      if(!visited[i])
      {
         bfs(adjlist,visited,n,i);
      }
   }


   

   return 0;
    
}