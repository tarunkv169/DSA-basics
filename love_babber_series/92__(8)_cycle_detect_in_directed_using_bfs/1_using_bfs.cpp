// if valid topological sort----->directed acyclic graph
// if invalid topological sort----->directed cyclic graph----this will give us ans true if exits cyclic

// just instead of ans we use count----(count==nodes)--- valid T.S ---acyclic---
//                                 ----(count!=nodes)--- invalid T.S ---cyclic--- 


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    //            STEP 1. CREATE ADAJACNY LIST
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


    //        STEP 2. FIND INDEGREE OF ALL NODES
    vector<int> indegree(n + 1, 0);  // intial all are zero

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<adjlist[i].size();j++)
        {
             indegree[adjlist[i][j]]++;
        }
    }

    //        STEP 3. PUSH NODE(INDEGREE '0') INTO QUEUE
    queue<int> q;
    for(int i=1;i<=n;i++)
    { 
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }


    //         STEP 4. DO BFS IN WHICH (1.find adj(of front node of queue) and reduce its degree)
    //                                 (2.store front into ans)

    int count=0;

    while(!q.empty())
    {
        int front=q.front();
        q.pop();

        count++;

        for(int i=0;i<adjlist[front].size();i++)
        {
            int neighbour=adjlist[front][i];

            indegree[neighbour]--;   // adjcent(neighbour) node ki indgree -- ki

            if(indegree[neighbour]==0)
            {
                q.push(neighbour); // pushing hoti rhegi iterate hota rhega 
            }
        }
    }

    
    if(count==n)   // valid T.S ---acyclic---
    {
        cout<<"not directed cyclic graph"<<endl;
    }
    else           // invalid T.S----cyclic--
    {
        cout<<"yes,  directed cyclic graph"<<endl;
    }
}