#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(vector<pair<int, int> > graph[], int src, int v) {
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
            if(dist[graph[temp][i].first] > dist[temp] + graph[temp][i].second) {
                dist[graph[temp][i].first] = dist[temp] + graph[temp][i].second;
                q.push(graph[temp][i].first);
            }
        }
    }

    return dist;

}

int main() {
    int v, e;
    cin >> v >> e;
    vector<pair<int, int> > graph[v];
    vector<int> result;

    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        graph[u].push_back(make_pair(v, w));
    }

    result = shortestPath(graph, 0, v);

    for(int i = 0; i < v; i++) {
        cout << i << " shortest ditance from 0 is " << result[i] << "\n";
    }
    return 0;
}