#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> bfs(vector<int> adjlist[],bool visited[],vector<int> &ans,int firstnode)
{
    //step(4)-----creating a queue and enqueue the first node and set enqueued node as visited
    queue<int> q;
    q.push(firstnode);
    visited[firstnode]=true;

    while(!q.empty())
    {
        int frontnode=q.front();
        q.pop();

        ans.push_back(frontnode);

        for(int i=0 ; i<adjlist[frontnode].size() ; i++)
        {
              if(!visited[adjlist[frontnode][i]])
              {
                q.push(adjlist[frontnode][i]);
                visited[adjlist[frontnode][i]]=true;
              }
        }
    }

    return ans;
}


int main()
{  // step(1)----creating (adjceny vector list(not array it is vector list)) of graph
    cout<<"enter the total no. of nodes/vertices "<<endl;
    int n;
    cin>>n;
    
    cout<<"enter the total no. of edges "<<endl;
    int e;
    cin>>e;

    vector<int> adjlist[n]; //vector list
    cout<<"enter 0 for undirected graph and 1 for directed"<<endl;
    int direction;
    cin>>direction;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adjlist[u].push_back(v);
        if(direction==0)
        {
            adjlist[v].push_back(u);
        }

    }

    // printing adjlist
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }


    //step(2)-----creating visited array and intialize with false
    bool visited[n]={false};

    //step(3)------creating vector to store answer
    vector<int> ans;


    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(adjlist,visited,ans,0);
        }
    }

    // step(5)-----printting answer(bfs traversal)
    cout<<"bfs traversal is ";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}