#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;

vector<int> prepare_adjlist(unordered_map<int,set<int>> &adjlist,vector<pair<int,int>> &edges)
{
     for(int i=0;i<edges.size();i++)
     {
          int u=edges[i].first;
          int v=edges[i].second;

          adjlist[u].insert(v);
          adjlist[v].insert(u);
     }
}

void print_adjlist(unordered_map<int,set<int>> &adjlist)
{
     for(auto i:adjlist)
     {
          cout<<i.first<<"->";
          for(auto j:i.second)
          {
               cout<<j<<" ";
          }
          cout<<endl;
     }
}


void bfs(unordered_map<int,set<int>> &adjlist , unordered_map<int,bool> &visited , vector<int> &ans , int firstnode)
{
    queue<int> q;
    q.push(firstnode);
    visited[firstnode]=1;

    while(!q.empty())
    {
        int frontnode=q.front();
        q.pop();

        ans.push_back(frontnode);

        for(auto i: adjlist[frontnode])
        {
             if(!visited[i])
             {
               q.push(i);
               visited[i]=1;
             }
        }
    }
}

vector<int> BFS(int vertex , vector<pair<int,int>> edges)
{
     unordered_map<int,set<int>> adjlist;
     prepare_adjlist(adjlist, edges);
     print_adjlist(adjlist);


     unordered_map<int,bool> visited;
     vector<int> ans;

     for(int i=0;i<vertex;i++)
     {
         if(!visited[i])
         {
             bfs(adjlist,visited,ans,i);
         }
     }

     return ans;
}
int main()
{
     // Example usage
    int vertex = 5;
    vector<pair<int, int>> edges = { {0, 3}, {3, 1}, {1, 2}, {1, 4} };

    vector<int> result = BFS(vertex, edges);

    // Print the BFS traversal result
    cout << "BFS Traversal: ";
    for (auto node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
      
}