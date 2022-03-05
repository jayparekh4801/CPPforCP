#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isValid(vector<int> graph[], int src, int vis[], int col) {
    for(int it : graph[src]) {
        if(vis[it] == col) {
            return false;
        }
    }

    return true;
}

bool solve(vector<int> graph[], int m, int vis[], int v) {
    
    for(int i = 0; i < v; i++) {
        if(vis[i] == -1) {
            for(int j = 0; j < m; j++) {
                if(isValid(graph, i, vis, j)) {
                    vis[i] = j;
                    if(solve(graph, m, vis, v) == true) {
                        return true;
                    }
                    else {
                        vis[i] = -1;
                    }
                }
            }  
            return false;
        }
    }

    return true;
}

bool mColoring(vector<int> graph[], int m, int v) {
    int vis[v];

    for(int i = 0; i < v; i++) {
        vis[i] = -1;
    }

    return solve(graph, m, vis, v);
}

int main() {
    int v, e, m;
    cin >> v;
    cin >> e;

    vector<int> graph[v];

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> m;

    bool result = mColoring(graph, m, v);

    if(result) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}