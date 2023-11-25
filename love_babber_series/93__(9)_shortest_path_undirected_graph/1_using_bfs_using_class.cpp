#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class UndirectedGraph {
public:
    int n;
    int e;
    int current;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> parent;
    vector<int> ans;

    UndirectedGraph(int nodes, int edges) : n(nodes), e(edges), adjList(nodes+1), visited(nodes, false), parent(nodes) {}

    void createAdjList() {
        cout << "Enter the pairs of edges:" << endl;
        for(int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }


    void print() {
        for(int i = 1; i <=n; i++) {
            cout << i << "->";
            for(int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }


    void bfs(int src, int dest) {
        visited[src]=true;
        parent[src]=true;
        queue<int> q;
        q.push(src);

        while(!q.empty()) 
        {
            int current_node = q.front();
            q.pop();
            
            for(int i = 0; i < adjList[current_node].size(); i++) 
            {
                int neighbor = adjList[current_node][i];

                if(!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    parent[neighbor] = current_node;
                    q.push(neighbor);
                }
            }
        }

        shortest_path(src, dest);
    }

    // jo destination tk pehle phunchega wo pehle parent hoga to parent to back traverse krne se shortest path mill jayega
     

    void shortest_path(int src, int dest) 
    {
        current = dest;
        ans.push_back(current);
        while (current != src) 
        {  
            current = parent[current];
            ans.push_back(current);     // storing the path from dest to src
        }

        if (current == -1) {
            cout << "No path found from source to destination." << endl;
            return;
        }


        // reversing the to get path form src to dest
        cout << "Shortest Path from " << src << " to " << dest << ": ";
        for (int i = ans.size() - 1; i >= 0; i--) 
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }


};

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;

    cout << "Enter the number of edges: ";
    int e;
    cin >> e;

    UndirectedGraph graph(n, e);

    graph.createAdjList();
    graph.print();

    int source, destination;
    cout << "Enter source and destination nodes for BFS: ";
    cin >> source >> destination;

    graph.bfs(source, destination);

    return 0;
}
