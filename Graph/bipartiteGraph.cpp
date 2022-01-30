#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<int> graph[], int v, bool vis[], int col[]) {
    queue<int> q;
    col[0] = 1;
    q.push(0);
    vis[0] = true;

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for(int i : graph[temp]) {
            if(col[i] == -1 && vis[i] == false) {
                vis[i] = true;
                col[i] = 1 - col[temp];
                q.push(i);
            }
            else if(vis[i] && col[i] == col[temp]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<int> graph[n];
    bool vis[n];
    int col[n];

    for(int i = 0; i < n; i++) {
        vis[i] = false;
        col[i] = -1;
    }

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool result = isBipartite(graph, n, vis, col);

    if(result) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}