#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int vertex;
    vector<int> *adj;

    Graph(int vertex);   // Конструктор

    void addEdge(int u, int v, bool isBidirectional); // добавление ребер

    void bfs(int src); // bfs alg

    void print(); // Вывод на экран списка соседей каждой вершины

};

Graph::Graph(int vertex) {
    this->vertex = vertex;
    this->adj = new vector<int>[vertex];
}

void Graph::addEdge(int u, int v, bool isBidirectional = true) {
    adj[u].push_back(v);
    if (isBidirectional) {   // Если двунаправленный
        adj[v].push_back(u);
    }
}

void Graph::bfs(int src) {
    queue<int> q;
    vector<bool> visited(vertex + 5, 0);

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int neighbour: adj[node]) {
            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}


void Graph::print() {
    for (int i = 0; i < vertex; i++) {
        cout << i << "-> ";
        for (int node: adj[i])//int j = 0; j < adj[i].size(); j++)
        {
            cout << node << ",";//adj[i][j] << ", ";
        }
        cout << endl;
    }
}


