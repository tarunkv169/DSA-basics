#include<iostream>
#include<vector>
#include <numeric> // for std::iota
using namespace std;

class disjoint
{
    public:
      vector<int> parent;
      vector<int> rank;

      disjoint(int nodes):parent(nodes+1,nodes),rank(nodes+1,0)
      {
        iota(parent.begin(), parent.end(), 0);
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
         //           STEP (2.1)-find parent of nodes u and v
         int p_u = find_parent(u);
         int p_v = find_parent(v);

         //           STEP (2.2)-check rank of parents and make parent as respective condi and == conde increament rank of parent
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
};

int main()
{
    // //                   STEP 1. TAKE INPUT (nodes,parentarr,rankarr) and itialize them
    // cout<<"enter the total no. of nodes"<<endl;
    // int n;
    // cin>>n;
    
    // disjoint d(n);

    // //                   STEP 2. make_union of two nodes
    // cout<<"enter the pair of nodes to union them "<<endl;
    // for(int i=0;i<n-1;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     d.make_union(u,v);
    // }
    
    

     //                   STEP 1. TAKE INPUT (nodes,parentarr,rankarr) and itialize them
     disjoint d(7);
     //                   STEP 2. make_union of two nodes
     d.make_union(1,2);
     d.make_union(2,3);
     d.make_union(4,5);
     d.make_union(6,7);
     d.make_union(5,6);

     if(d.find_parent(3)==d.find_parent(7))
     {
        cout<<"nodes belongs to same component"<<endl;
     }
     else
     {
        cout<<"nodes belong to different components"<<endl;
     }

     d.make_union(3,7);

     if(d.find_parent(3)==d.find_parent(7))
     {
        cout<<"nodes belongs to same component"<<endl;
     }
     else
     {
        cout<<"nodes belong to different components"<<endl;
     }

     return 0;
}