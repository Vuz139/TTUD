#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet
{
    vector<int> parent, rank;

    // Constructor
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        // Initialize each element as a separate set with itself as the parent
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find the parent of a set
    int find(int u)
    {
        if (parent[u] != u)
            parent[u] = find(parent[u]);

        return parent[u];
    }

    // Union of two sets by rank
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (rank[u] > rank[v])
            parent[v] = u;
        else
            parent[u] = v;

        if (rank[u] == rank[v])
            ++rank[v];
    }
};

// Comparator function to sort edges based on weight
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

// Kruskal's algorithm to find MST
int kruskalMST(const vector<Edge> &edges, int V)
{
    int result = 0; // Stores the MST

    // Sort edges in non-decreasing order of their weights
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    DisjointSet ds(V);

    // Process each edge in the sorted order
    for (const auto &edge : sortedEdges)
    {
        int u = edge.src;
        int v = edge.dest;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // If including this edge does not form a cycle, add it to the MST
        if (set_u != set_v)
        {
            result += edge.weight;
            ds.merge(set_u, set_v);
        }
    }

    return result;
}

int main()
{
    freopen("input.inp", "r", stdin);
    int V, E;

    cin >> V;

    cin >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int mst = kruskalMST(edges, V);
    cout << mst << endl;
    return 0;
}
