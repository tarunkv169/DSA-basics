/*
 u can try 
 enter the no. of nodes
6
enter the no. of edges
9
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
4 5 -2

*/

#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

class graph
{
    public:
      int n;
      int e;
      vector<vector<pair<int,int>>> adjlist; // vector list ko v vector bna diya jisme pairing hogi so that no need to do vector<int> adjlist[n]
      vector<int> visited;
      stack<int> topo_sort;
      //                   step3. creating distance array initializing with infinity
      vector<int> distarr;
      
                                                                                       // step3.
      graph(int nodes,int edges): n(nodes),e(edges),adjlist(nodes),visited(nodes,false),distarr(nodes,INT_MAX){}
      


      void create_weighted_adjlist(int u,int v,int w)
      {        
              adjlist[u].push_back({v,w});
      }



      void print_adjlist()
      {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<adjlist[i].size();j++)
            {                
                              //this is adjnode              //this is adjnode weight
                cout << "[" << adjlist[i][j].first << " " << adjlist[i][j].second << "] ";
            }
            cout<<endl;
        }
      }

      
      void dfs(int src)
      {
        visited[src]=true;

        for(int i=0;i<adjlist[src].size();i++)
        {
            int neighbour=adjlist[src][i].first;
            if(!visited[neighbour])
            {
                dfs(neighbour);
            }
        }

        topo_sort.push(src);
      }


    //   void print_topo_sort()
    //   {
    //     for(int i=0;i<n;i++)
    //     {
    //         cout<<topo_sort.top()<<" ";
    //         topo_sort.pop();
    //     }
    //   }


      void shortest_path(int src)
      {
        distarr[src]=0;

        while(!topo_sort.empty())
        {
            int top=topo_sort.top();
            topo_sort.pop();

            if(distarr[top]!=INT_MAX)
            {
                for(int i=0;i<adjlist[top].size();i++)
                {     //top_ele_weight +   adj_ele_weight        < distarr me stored uss adj_ele ki value se
                    if(distarr[top]    +  adjlist[top][i].second < distarr[adjlist[top][i].first])
                    {    
                        // if condi stisfy then update distarr with small value
                         distarr[adjlist[top][i].first]=distarr[top]+adjlist[top][i].second;
                    }
                }
            }
        }
      }

      void print_distarr()
      {
         for(int i=0;i<distarr.size();i++)
         {
             cout<<distarr[i]<<" ";
         }
      }

};

int main()
{
    //                      STEP 1. CREATING weighted_ADJACENYLIST USING (vector pair list)
    cout<<"enter the no. of nodes"<<endl;
    int n;
    cin>>n;

    cout<<"enter the no. of edges "<<endl;
    int e;
    cin>>e;

    graph g(n,e);

    cout<<"enter the edges and their weight "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.create_weighted_adjlist(u,v,w);
    }
    
     g.print_adjlist();


     //                  step2. creating topological sort using (dfs)

     cout<<"enter the source"<<endl;
     int source;
     cin>>source;

     g.dfs(source);
     cout<<"topological sorted is "<<endl;
    //  g.print_topo_sort();
     cout<<endl;

     
     
     //                   step4. updating distance array with help of stack of topo_sort
     cout<<"enter the source form where distance is to find "<<endl;
     int src;
     cin>>src;
     g.shortest_path(src);

     cout<<"the distance array is "<<endl;
     g.print_distarr();


     return 0;
     
}