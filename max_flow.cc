#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Định nghĩa đồ thị bằng ma trận kề
class Graph
{
    int V; // Số đỉnh của đồ thị

public:
    Graph(int V);
    void addEdge(int u, int v, int capacity);
    bool BFS(vector<vector<int>> &residualGraph, int s, int t, vector<int> &parent);
    int maxFlow(int s, int t);
};

Graph::Graph(int V)
{
    this->V = V;
}

void Graph::addEdge(int u, int v, int capacity)
{
    // Mỗi cạnh có thể có nhiều cạnh liên thông với cạnh đó
    vector<int> edge1 = {v, capacity, 0}; // Đỉnh đến, dung lượng, luồng hiện tại
    vector<int> edge2 = {u, 0, 0};        // Đỉnh đến, dung lượng, luồng hiện tại

    // Thêm các cạnh vào đồ thị
    residualGraph[u].push_back(edge1);
    residualGraph[v].push_back(edge2);
}

bool Graph::BFS(vector<vector<int>> &residualGraph, int s, int t, vector<int> &parent)
{
    vector<bool> visited(V, false); // Mảng đánh dấu các đỉnh đã được thăm
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && residualGraph[u][v][1] > 0)
            { // Nếu đỉnh chưa được thăm và còn dung lượng cạnh dương
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // Trả về kết quả xem có thể đi từ đỉnh nguồn đến đỉnh đích hay không
    return visited[t];
}

int Graph::maxFlow(int s, int t)
{
    vector<vector<int>> residualGraph(V, vector<int>(V, 0)); // Đồ thị còn lại sau khi luồng đã chảy
    vector<int> parent(V, -1);                               // Mảng cha để lưu đường đi từ BFS

    // Khởi tạo đồ thị còn lại với giá trị ban đầu bằng giá trị ban đầu của đồ thị gốc
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int maxFlow = 0; // Luồng cực đại

    // Tiếp tục tìm đường tăng luồng từ đỉnh nguồn đến đỉnh đích
    while (BFS(residualGraph, s, t, parent))
    {
        int pathFlow = INT_MAX;

        // Tìm giá trị luồng tăng trên đường tăng luồng
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v][1]);
        }

        // Cập nhật đồ thị còn lại sau khi luồng tăng
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v][1] -= pathFlow; // Giảm dung lượng cạnh
            residualGraph[v][u][1] += pathFlow; // Tăng dung lượng cạnh ngược lại
        }

        maxFlow += pathFlow; // Cộng dồn luồng tăng vào luồng cực đại
    }

    return maxFlow;
}

int main()
{
    freopen("input.inp", "r", stdin);
    int V, E;
    cin >> V;

    cin >> E;
    int source, sink;
    cin >> source;

    cin >> sink;
    Graph graph(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph.addEdge(u, v, capacity);
    }

    int maxFlow = graph.maxFlow(source, sink);
    cout << "Max Flow: " << maxFlow << endl;

    return 0;
}
