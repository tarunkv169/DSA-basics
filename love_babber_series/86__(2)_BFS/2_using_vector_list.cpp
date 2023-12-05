#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> bfs(vector<int> adjlist[],bool visited[],vector<int> &ans,int current_node)
{
    //                       step(4)-----creating a queue and enqueue the first node and set enqueued node as visited
    // IQ VT DQ IA IA VT
    queue<int> q;
    q.push(current_node);
    visited[current_node]=true;

    while(!q.empty())
    {
        int current_node=q.front();
        q.pop();

        ans.push_back(current_node);

        for(int i=0 ; i<adjlist[current_node].size() ; i++)  //jo current_node ke adjacent nodes hain(jo ki adjlist mein hamne store kiye the like 1->2,4,5) unko iterate kr rhe hain
        {     //adjlist[current_node][i]---we check first adjacent node(of our current_node) is it visited
              if(!visited[adjlist[current_node][i]])
              {
                q.push(adjlist[current_node][i]);    
                visited[adjlist[current_node][i]]=true;
              }
        }
    }

    return ans;
}


int main()
{  //                 step(1)----creating (adjceny vector list(not array it is vector list)) of graph
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


    //                       step(2)-----creating visited array and intialize with false
    bool visited[n]={false};

    //                       step(3)------creating vector to store answer
    vector<int> ans;


    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(adjlist,visited,ans,0);
        }
    }

    //                       step(5)-----printting answer(bfs traversal)
    cout<<"bfs traversal is ";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}