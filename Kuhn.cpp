#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int vertex;
    vector<int> *adj;

    Graph(int vertex);   // Конструктор

    void addEdge(int u, int v, bool isBidirectional); // добавление ребер

    void print(); // Вывод на экран списка соседей каждой вершины

    int maxBPM(); // Алгоритм Куна для поиска максимального паросочетания

    bool bpm(int u, int matchR[], bool seen[]);
};

Graph::Graph(int vertex) {
    this->vertex = vertex;
    this->adj = new vector<int>[vertex];
}

void Graph::addEdge(int u, int v, bool isBidirectional = false) {
    adj[u].push_back(v);
    if (isBidirectional) {   // Если двунаправленный
        adj[v].push_back(u);
    }
}

void Graph::print() {
    for (int i = 0; i < vertex; i++) {
        cout << i << "-> ";
        for (int node : adj[i]) {
            cout << node << ",";
        }
        cout << endl;
    }
}

bool Graph::bpm(int u, int matchR[], bool seen[]) {
    for (int v : adj[u]) {
        if (!seen[v]) {
            seen[v] = true;
            if (matchR[v] == -1 || bpm(matchR[v], matchR, seen)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int Graph::maxBPM() {
    int matchR[vertex];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < vertex; u++) {
        bool seen[vertex];
        memset(seen, 0, sizeof(seen));
        if (bpm(u, matchR, seen)) {
            result++;
        }
    }
    return result;
}

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 7);
    g.addEdge(6, 5);
    cout << "Maximum Bipartite Matching: " << g.maxBPM() << endl; // 4
    return 0;
}