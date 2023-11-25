// topological sort------(1)as u->v  evey u should before v
//                       (2)applied only on directed acyclic graph
//                       (3)need of stack 

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void topological_sort(vector<int> adjlist[],bool visited[],stack<int> &s,int n,int src)
{
     visited[src]=true;

     for(int i=0;i<adjlist[src].size();i++)
     {
        int neighbour=adjlist[src][i];
        if(!visited[neighbour])
        {
            topological_sort(adjlist,visited,s,n,neighbour);
        }
     }

     s.push(src);
}

int main()
{
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


    bool visited[n]={false};
    stack<int> s;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            topological_sort(adjlist,visited,s,n,i);
        }
    }


    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }


    return 0;

}

