#include <iostream>
#include <vector>
#include <set>

using namespace std;

void articulations(vector<int> graph[], int tin[], int low[], bool vis[], int& timer, set<int>& aux, int parent, int s) {
    vis[s] = true;
    low[s] = tin[s] = timer++;
    for(int it : graph[s]) {
        if(it == parent) {
            continue;
        }

        if(!vis[it]) {
            articulations(graph, tin, low, vis, timer, aux, s, it);
            low[s] = min(low[s], low[it]);
            if(low[it] > tin[s]) {
                if(graph[s].size() > 1) {
                    aux.insert(s);
                }
                if(graph[it].size() > 1) {
                    aux.insert(it);
                }
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

    vector<int> graph[n];
    vector<int> result;
    set<int> aux;
    int tin[n];
    int low[n];
    bool vis[n];
    int timer = 0;

    for(int i = 0; i < n; i++) {
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

    articulations(graph, tin, low, vis, timer, aux, -1, 0);

    set<int> :: iterator itr;

    for(itr = aux.begin(); itr != aux.end(); ++itr) {
        result.push_back(*itr);
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}