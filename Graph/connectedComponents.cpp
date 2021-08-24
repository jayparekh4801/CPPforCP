#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void addEdge(vector<int> graph[], int src, int dest) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

void DFS(vector<int> graph[], int v, int src, bool vis[]) {
    stack<int> s;
    s.push(src);
    vis[src] = true;

    while(!s.empty()) {
        int temp = s.top();
        cout << temp;
        
        s.pop();
        for(int i = 0; i < graph[temp].size(); i++) {
            if(!vis[graph[temp][i]]) {
                s.push(graph[temp][i]);
                vis[graph[temp][i]] = true;
            }
        }
    }
}

void stronglyConnected(vector<int> graph[], int v) {
    bool vis[v + 1];
    for(int i = 0; i < v; i++) {
        vis[i] = false;
    }

    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            DFS(graph, v, i, vis);
            cout << "\n";
        } 
    }
}

int main() {
    int v = 5;
    vector<int> graph[v];

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
   

    stronglyConnected(graph, v);
    return 0;
}