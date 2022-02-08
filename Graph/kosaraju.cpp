#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<int> graph[], bool vis[], int src, stack<int>& st) {
    vis[src] = true;

    for(int it : graph[src]) {
        if(!vis[it]) {
            DFS(graph, vis, it, st);
        }
    }

    st.push(src);
}

void revDFS(vector<int> graph[], bool vis[], int src) {
    vis[src] = true;

    for(int it : graph[src]) {
        if(!vis[it]) {
            revDFS(graph, vis, it);
        }
    }
}

int kosaraju(vector<int> graph[], int v) {

    int result = 0;
    stack<int> st;
    bool vis[v];

    for(int i = 0; i < v; i++) {
        vis[i] = false;
    }
    
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            DFS(graph, vis, i, st);
        }
    }

    vector<int> transpose[v];

    for(int i = 0; i < v; i++) {
        vis[i] = false;
        for(int it : graph[i]) {
            transpose[it].push_back(i);
        }
    }

    while(!st.empty()) {
        int temp = st.top();
        st.pop();
        if(!vis[temp]) {
            result++;
            revDFS(transpose, vis, temp);
        }
    }

    return result;
}

int main() {
    int v, e;
    int result = 0;

    cin >> v;
    cin >> e;

    vector<int> graph[v];

    for(int i = 0; i < e; i++) {
        int u, v;

        cin >> u;
        cin >> v;

        graph[u].push_back(v);
    }

    result = kosaraju(graph, v);
    cout << result;

    return 0;
}