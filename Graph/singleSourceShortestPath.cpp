#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(vector<int> graph[], int src, int v) {
    vector<int> dist(v);
    queue<int> q;

    for(int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
    }

    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int temp = q.front(); 
        q.pop();
        for(int i = 0; i < graph[temp].size(); i++) {
            if(dist[graph[temp][i]] > dist[temp] + 1) {
                dist[graph[temp][i]] = dist[temp] + 1;
                q.push(graph[temp][i]);
            }
        }
    }

    return dist;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];
    vector<int> result;

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    result = shortestPath(graph, 0, v);

    for(int i = 0; i < v; i++) {
        cout << i << " shortest distance from 0 " << result[i] << "\n";
    }

    return 0;
}