#include <iostream>
#include <vector>

using namespace std;

void printBridges(vector<int> graph[], int parent, int low[], int tin[], bool vis[], int& timer, int s) {
    vis[s] = true;
    tin[s] = low[s] = timer++;
    for(int it : graph[s]) {
        if(it == parent) {
            continue;
        }
        if(!vis[it]) {
            printBridges(graph, s, low, tin, vis, timer, it);
            low[s] = min(low[s], low[it]);
            if(low[it] > tin[s]) {
                cout << s << " - " << it << "\n";
            }
        }
        else {
            low[s] = min(low[s], tin[it]);
        }
    }
}

int main() {
    int n, e;
    cin >> n;
    cin >> e;
    vector<int> graph[n + 1];
    bool vis[n + 1];
    int tin[n + 1];
    int low[n + 1];
    int timer = 0;

    for(int i = 0; i < n + 1; i++) {
        tin[i] = -1;
        low[i] = -1;
        vis[i] = false;
    }

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i < n + 1; i++) {
        if(!vis[i]) {
            printBridges(graph, -1, low, tin, vis, timer, i);
        }
    }
    return 0;
}