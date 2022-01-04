#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topoSort(vector<int> graph[], int v) {
    int inDegree[v];
    queue<int> q;
    vector<int> result;
    for(int i = 0; i < v; i++) {
        inDegree[i] = 0;
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            inDegree[graph[i][j]]++;
        }
    }

    for(int i = 0; i < v; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        result.push_back(temp);

        for(int i = 0; i < graph[temp].size(); i++) {
            inDegree[graph[temp][i]]--;
            if(inDegree[graph[temp][i]] == 0) {
                q.push(graph[temp][i]);
            }
        }
    }

    return result;

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
    }

    result = topoSort(graph, v);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}