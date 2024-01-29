// topological sort------(1)as u->v  evey u should before v
//                       (2)applied only on directed acyclic graph
//                       (3)need of stack 

// nothing special we are applying same dfs just storing node in stack which doesnot have adjcent left to call

//u can try:-
/*
enter the no. of nodes 
6
enter the no. of edges 
7
enter the edges 
1 2
1 3
2 4
3 4
4 5
4 6
5 6
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void dfs_toposort(vector<int> adjlist[],bool visited[],stack<int> &topo_sort,int n,int src)
{
     visited[src]=true;

     for(int i=0;i<adjlist[src].size();i++)
     {
        int neighbour=adjlist[src][i];
        if(!visited[neighbour])
        {
            dfs_toposort(adjlist,visited,topo_sort,n,neighbour);
        }
     }
     
     //  after all recursive call occur now it is backtracking and execute the remaing lines of function
     // during  this backtrack we add that node into stack
     topo_sort.push(src);
}

int main()
{  //             step 1. creating adjlist
    cout<<"enter the no. of nodes "<<endl;
    int n;
    cin>>n;

    cout<<"enter the no. of edges "<<endl;
    int e;
    cin>>e;

    vector<int> adjlist[n+1];
    cout<<"enter the edges "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        //due to directed
        adjlist[u].push_back(v);

    }
    
    cout<<"adjaceny list is "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }

   //              step2. calling dfs for topological sort(declaring visisted and stack)
    bool visited[n]={false};
    stack<int> topo_sort;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs_toposort(adjlist,visited,topo_sort,n,i);
        }
    }


    for(int i=0;i<n;i++)
    {
        cout<<topo_sort.top()<<" ";
        topo_sort.pop();
    }


    return 0;

}

