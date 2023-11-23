#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class graph
{
    public:
       unordered_map<T,list<T>> adj;

       void addedge(T u,T v,bool direction)
       {
          //if direction=0-->undirected graph
          //if direction=1-->directed graph

          // creating edge from u to v
          adj[u].push_back(v);

          // creating edge from v to u if undirected graph
          if(direction==0)
          {
            adj[v].push_back(u);
          }
       }

       void print()
       {
         for(auto i:adj)
         {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
         }
       }
     
};

int main()
{
    graph<int> g;

    cout<<"enter the no. of nodes"<<endl;
    int n;
    cin>>n;

    cout<<"enter the no. of edges"<<endl;
    int e;
    cin>>e;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);//for undirected graph
    }

    g.print();

    return 0;
}