#include<iostream>
#include<vector>
#include <numeric> // for std::iota
using namespace std;

class graph
{
    public:
      int n;
      int e;
      vector<vector<pair<int,int>>> adjlist;
      vector<int> parent;
      vector<int> rank;
      vector<pair<int,pair<int,int>>> weighted_edges;

      graph(int nodes,int edges):n(nodes),e(edges),adjlist(nodes),parent(nodes+1,nodes),rank(nodes+1,0)
      {
        iota(parent.begin(), parent.end(), 0);
      }
      
      void create_adjlist(int u,int v,int w)
      {
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
      }

      void print_adjlist()
      {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<adjlist[i].size();j++)
            {
                cout<<"["<<adjlist[i][j].first<<","<<adjlist[i][j].second<<"]"<<" ";
            }
            cout<<endl;
        }
      }
      
      int find_parent(int node)
      {
          if(node==parent[node])
          {
             return node;
          }

          return parent[node]=find_parent(parent[node]);
      }

      void make_union(int u,int v)
      {
        int p_u = find_parent(u);
        int p_v = find_parent(v);

        if(rank[p_u]>rank[p_v])
         {
            parent[p_v]=p_u;
         }
         else if(rank[p_u]<rank[p_v])
         {
            parent[p_u]=p_v;
         }
         else
         {
            parent[p_v]=p_u;
            rank[p_u]++;
         }
      }
       

    // Bubble sort for sorting weighted_edges
    void bubbleSort() {
        for (int i = 0; i < e - 1; i++) {
            for (int j = 0; j < e - i - 1; j++) {
                if (weighted_edges[j].first > weighted_edges[j + 1].first) {
                    swap(weighted_edges[j], weighted_edges[j + 1]);
                }
            }
        }
    }


      int krushal_algo()
      {
         for(int i=0;i<n;i++)
         {
            for(int j=0;j < adjlist[i].size();j++)
            {
                int adjnode=adjlist[i][j].first;
                int u=i;
                int w=adjlist[i][j].second;
                
                weighted_edges.push_back({w,{u,adjnode}});
            }
         }

         bubbleSort();

         int minweight=0;
         for(int i=0;i<weighted_edges.size();i++)
         {
            int weight=weighted_edges[i].first;
            int u=weighted_edges[i].second.first;
            int v=weighted_edges[i].second.second;

            if(find_parent(u)!=find_parent(v))
            {
                 minweight=minweight + weight;
                 make_union(u,v);
            }
         }

         return minweight;
      }
};

int main()
{
    cout<<"enter the total no. of nodes"<<endl;
    int n;
    cin>>n;
    cout<<"enter the total no. of edges"<<endl;
    int e;
    cin>>e;

    graph g(n,e);
    cout<<"enter the edges"<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.create_adjlist(u,v,w);
    }
    
    int miniweight=g.krushal_algo();
    
    cout<<"cost weight for minimum spanning tree"<<miniweight<<endl;

}