// using vectorlist----- using class 


#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class undirected_graph
{
    public:
      int n;
      int e;
      vector<vector<int>> adjlist;
      vector<bool> visited;


      undirected_graph(int nodes,int edges): n(nodes), e(edges), adjlist(nodes+1), visited(nodes, false){}
      

      void create_adjlist()
      {
          cout<<"enter the pair of edges "<<endl;
          for(int i=0;i<e;i++)
          {
              int u,v;
              cin>>u>>v;

              adjlist[u].push_back(v);
              adjlist[v].push_back(u);
          }
      }

      void print()
      {
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
};

int main()
{
    cout<<"enter the no. of nodes "<<endl;
    int n;
    cin>>n;
    cout<<"enter the edges "<<endl;
    int e;
    cin>>e;
    
    undirected_graph ug(n,e);

    ug.create_adjlist();

    ug.print();

}