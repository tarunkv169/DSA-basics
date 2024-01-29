#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class graph
{
public:
    int n;
    int e;
    int sum;
    vector<vector<pair<int, int>>> adjlist;
    vector<bool> mst_visited;
    vector<int> distarr;
    vector<int> parent;

    vector<pair<pair<int,int>,int>> result;

    graph(int nodes, int edges) : n(nodes), e(edges), adjlist(nodes), distarr(nodes, INT_MAX), mst_visited(nodes, false), parent(nodes, -1),sum(0) {}

    void create_weighted_adjlist(int u, int v, int w)
    {
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }

    void print_adjlist()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "->";
            for (int j = 0; j < adjlist[i].size(); j++)
            {
                cout << "[" << adjlist[i][j].first << "," << adjlist[i][j].second << "]"
                     << " ";
            }
            cout << endl;
        }
    }

    void prims(int src)
  {
    distarr[src] = 0;
    parent[src] = -1;
    mst_visited[src] = true;

    for (int count = 0; count < n - 1; count++)
    {
        int smallest = INT_MAX;
        int smallest_node;

        // Loop over all nodes
        for (int i = 0; i < n; i++)
        {
            if (mst_visited[i])
            {
                // Loop over all neighbors of the current node
                for (int j = 0; j < adjlist[i].size(); j++)
                {
                    int neighbour = adjlist[i][j].first;
                    int neighbour_weight = adjlist[i][j].second;

                    // Check if the neighbour is not in MST and the weight is smaller
                    if (!mst_visited[neighbour] && neighbour_weight < distarr[neighbour])
                    {
                        distarr[neighbour] = neighbour_weight;
                        parent[neighbour] = i; // Update parent for the neighbour
                    }
                }
            }
        }

        // Find the smallest node not yet in MST
        for (int i = 0; i < n; i++)
        {
            if (!mst_visited[i] && distarr[i] < smallest)
            {
                smallest = distarr[i];
                smallest_node = i;
            }
        }

        // Mark the smallest node as visited and update the current source
        mst_visited[smallest_node] = true;
        src = smallest_node;

        // Store the result
        result.push_back({{parent[smallest_node], smallest_node}, distarr[smallest_node]});
    }
  }


  void print_result()
  {
    cout << "Minimum Spanning Tree Edges and Weights:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "(" << result[i].first.first << " - " << result[i].first.second << ") : " << result[i].second << endl;
    }
   }



    void print_parentarr()
    {
        for (int i = 0; i < n; i++)
        {
            sum=sum+distarr[i];
        }
        cout<<sum<<endl;
    }
};

int main()
{
    cout << "enter the total no. of nodes " << endl;
    int n;
    cin >> n;
    cout << "enter the total no. of edges " << endl;
    int e;
    cin >> e;

    graph g(n, e);

    cout << "enter the pairs of nodes(edges) and weight" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.create_weighted_adjlist(u, v, w);
    }

    g.print_adjlist();

    cout << "enter the src from where u want to start" << endl;
    int src;
    cin >> src;
    g.prims(src);
    g.print_result();  // Print the result after running Prim's algorithm
    g.print_parentarr();
}
