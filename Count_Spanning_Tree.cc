#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Định nghĩa cấu trúc đỉnh của đồ thị
struct Node
{
    int id;
    vector<Node *> neighbors;
    bool visited;

    Node(int _id) : id(_id), visited(false) {}
};

// Hàm đếm số cây khung
int countSpanningTrees(vector<Node *> &graph)
{
    int count = 0;
    for (Node *node : graph)
    {
        if (!node->visited)
        {
            count++;
            queue<Node *> q;
            q.push(node);

            while (!q.empty())
            {
                Node *current = q.front();
                q.pop();

                current->visited = true;

                for (Node *neighbor : current->neighbors)
                {
                    if (!neighbor->visited)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    return count;
}

int main()
{
    // Đồ thị ví dụ với 5 đỉnh và 6 cạnh
    vector<Node *> graph;
    for (int i = 0; i < 5; i++)
    {
        graph.push_back(new Node(i));
    }

    graph[0]->neighbors.push_back(graph[1]);
    graph[1]->neighbors.push_back(graph[0]);

    graph[1]->neighbors.push_back(graph[2]);
    graph[2]->neighbors.push_back(graph[1]);

    graph[2]->neighbors.push_back(graph[3]);
    graph[3]->neighbors.push_back(graph[2]);

    graph[3]->neighbors.push_back(graph[4]);
    graph[4]->neighbors.push_back(graph[3]);

    graph[4]->neighbors.push_back(graph[0]);
    graph[0]->neighbors.push_back(graph[4]);

    int spanningTreeCount = countSpanningTrees(graph);
    cout << "So luong cay khung: " << spanningTreeCount << endl;

    // Giải phóng bộ nhớ
    for (Node *node : graph)
    {
        delete node;
    }

    return 0;
}
