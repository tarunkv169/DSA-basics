

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
using namespace std;

int main() 
{
  cout<<"enter the no. of nodes"<<endl;
  int n; cin>>n;
  cout<<"enter the no. of edges "<<endl;
  int e; cin>>e;

  vector<vector<pair<int,int>>> adjlist; // adjacency list
  
  cout<<"enter the edges and their weights "<<endl;
  for(int i=0;i<e;i++) 
  {
    int u,v,w; 
    cin>>u>>v>>w; // read the edge (u,v,w)
    adjlist[u].push_back({v, w}); // add the edge (u,v) with weight w to the adjacency list of node u
  }

  for(int i=0;i<n;i++)
  {
     cout<<i<<"->";
     for(int j=0;j<adjlist[i].size();j++)
     {
        cout << "[" << adjlist[i][j].first << " " << adjlist[i][j].second << "] ";
     }
     cout<<endl;
  }

  return 0;
}