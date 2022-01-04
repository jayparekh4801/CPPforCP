#include <iostream>
#include <queue>

using namespace std;

void BFS(vector<int> graph[], int s, bool vis[]) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for(int i = 0; i < graph[temp].size(); i++) {
            if(!vis[graph[temp][i]]) {
                q.push(graph[temp][i]);
                vis[graph[temp][i]] = true;
            }
        }
    }
}

void BFSDriver(vector<int> graph[], int v) {
    bool vis[v + 1];

    for(int i = 0; i < v + 1; i++) {
        vis[i] = false;
    }

    for(int i = 1; i < v + 1; i++) {
        if(!vis[i]) {
            BFS(graph, i, vis);
        }
    }
}

int main() {
    int m, n;

    cin >> m >> n;

    vector<int> graph[m +1];

    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BFSDriver(graph, m);


    return 0;
}