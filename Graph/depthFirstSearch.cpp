#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int> graph[], bool vis[], int s) {
    cout << s << " ";
    vis[s] = true;

    for(int i : graph[s]) {
        if(!vis[i]) {
            DFS(graph, vis, i);
        }
    }
}

void dfsDriver(vector<int> graph[], int v) {
    bool vis[v + 1];

    for(int i = 0; i < v; i++) {
        vis[i] = false;
    }

    for(int i = 1; i < v; i++) {
        if(!vis[i]) {
            DFS(graph, vis, i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> graph[n + 1];
    int e;
    cin >> e;

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsDriver(graph, n);

    return 0;
}