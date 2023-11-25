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
    vector<int> distarr;
    vector<int> parent;
    vector<bool> mst;
    vector<pair<pair<int,int>,int>> result;

    graph(int nodes, int edges) : n(nodes), e(edges),sum(0), adjlist(nodes), distarr(nodes, INT_MAX), parent(nodes, -1), mst(nodes, false) {}

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
        mst[src] = true;

        for (int count = 0; count < n - 1; count++)
        {
            int smallest = INT_MAX;
            int smallest_node;

            for (int i = 0; i < n; i++)
            {
                if (mst[i])
                {
                    for (int j = 0; j < adjlist[i].size(); j++)
                    {
                        int neighbour = adjlist[i][j].first;
                        int neighbour_weight = adjlist[i][j].second;

                        if (!mst[neighbour] && neighbour_weight < distarr[neighbour])
                        {
                            distarr[neighbour] = neighbour_weight;
                        }

                        if (!mst[neighbour] && distarr[neighbour] < smallest)
                        {
                            smallest = distarr[neighbour];
                            smallest_node = neighbour;
                        }
                    }
                }
            }

            if (mst[smallest_node] == false)
            {
                mst[smallest_node] = true;
                parent[smallest_node] = src;
            }

            src = smallest_node;
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
    g.print_parentarr();
}
