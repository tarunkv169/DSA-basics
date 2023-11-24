/* dijkatra() algo     is same as       bfs algo
   distarr[]----------------------------visited[]
   set(pair(distance,node))-------------queue(push_node)
   */

/*
 u can try
enter the total no. of nodes
4
enter the total no. of edges
5
enter the pair of edges
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
enter the source form where u want to find the shortest_distance
0
0 5 8 7

*/


#include<iostream>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;

class graph
{
    public:
       int n;
       int e;
       vector<vector<pair<int,int>>> adjlist;
       vector<int> visited;
       vector<int> distarr;        // STEP 2. CREATING Distance array------------------ \|/ intializing all with infinity
       set<pair<int,int>> st;

       graph(int nodes,int edges):n(nodes),e(edges),adjlist(nodes),visited(nodes,false),distarr(nodes,INT_MAX){}

       void create_weighted_adjlist(int u,int v,int w)
       {
          adjlist[u].push_back({v,w});
          adjlist[v].push_back({u,w});
       }
 
       void print_weighted_adjlist()
       {
          for(int i=0;i<n;i++)
          {
              cout<<i<<" ";
              for(int j=0;j<adjlist[i].size();j++)
              {
                cout<<"["<<adjlist[i][j].first<<","<<adjlist[i][j].second<<"]"<<" ";
              }
              cout<<endl;
          }
       }



       void dijkstra(int src)
       {
          // 1.putting src distance=0-----------just like we set visited=true
          distarr[src]=0;
          
          // 2.inserting the making pair of (distance,node) into---------just like we push into queue
          st.insert(make_pair(0,src));
          
          while(!st.empty())
          { 
              // 3.fetch top record of set-------------------just same poping in queue
              auto top=*st.begin();
              int node_distance=top.first;
              int node=top.second;

              // 4.remove top record of set
              st.erase(st.begin());
              
              // 5.traverse the neighbour nodes
              for(int i=0;i<adjlist[node].size();i++)
              {    // in (simple vector list) if we want adjacent node of a node------adjlist[node][i]
                   // but in (vector pair list) if we want adjacent node of a node--------adjlist[node][i].first and weight adjlist[node][i].second ---due to pairing
                    int neighbour = adjlist[node][i].first;
                    int neighbour_weight = adjlist[node][i].second;
                   
                   // 6.updaing distance array by checking condi
                   if(node_distance + neighbour_weight < distarr[neighbour])
                   {   
                       // 7.checking pair already exist or not 
                       auto check_already_exist =st.find(make_pair(distarr[neighbour],neighbour));
                       if(check_already_exist!=st.end())
                       {
                           st.erase(check_already_exist);
                       }



                       distarr[neighbour]=node_distance + neighbour_weight;
                       
                       //insertain always in set making pairs of(distace,node)
                       // 8. here inserting new (distanac,node)
                       st.insert(make_pair(distarr[neighbour],neighbour));
                   }
              }

          }
       }

       void  print_shortest_path()
       {
        for(int i=0;i<distarr.size();i++)
        {
            cout<<distarr[i]<<" ";
        }
          
       }


};

int main()
{
    //             STEP 1. CREATING ADJACENY LIST USING (vector pair list) 
    cout<<"enter the total no. of nodes"<<endl;
    int n;
    cin>>n;

    cout<<"enter the total no. of edges"<<endl;
    int e;
    cin>>e;
    
    graph g(n,e);
    
    cout<<"enter the pair of edges "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.create_weighted_adjlist(u,v,w);
    }

    g.print_weighted_adjlist();

    //              STEP 3. updating distace array using dijkstra algo 
    cout<<"enter the source form where u want to find the shortest_distance"<<endl;
    int src;
    cin>>src;

    g.dijkstra(src);
    g.print_shortest_path();
    
}
