#include <iostream>
#include <vector>

using namespace std;

vector<int> bellamanFord(int v, vector<vector<int> > graph, int src) {
    vector<int> dis(v, INT_MAX);
    dis[src] = 0;
    int edges = graph.size();

    for(int i = 0; i < v - 1; i++) {
        for(int j = 0; j < edges; j++) {
            if(dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    }

    for(int j = 0; j < edges; j++) {
        if(dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) {
            dis.clear();
            cout << "Negative Cycle";
            break;
        }
    }

    return dis;

}

int main() {
    int v, e;
    int src;
    cin >> v;
    cin >> e;
    cin >> src;

    vector<vector<int> > graph(e);

    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        graph[i].push_back(u);
        graph[i].push_back(v);
        graph[i].push_back(w);
    }

    vector<int> result = bellamanFord(v, graph, src);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\t";
    }

    return 0;
}