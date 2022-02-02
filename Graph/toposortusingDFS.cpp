#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(vector<int> graph[], bool vis[], stack<int>& st, int s) {
    vis[s] = true;

    for(int i : graph[s]) {
        if(!vis[i]) {
            DFS(graph, vis, st, i);

        }
    }

    st.push(s);
}

int main() {
    int n, e;
    cin >> n;
    cin >> e;
    vector<int> graph[n];
    stack<int> st;
    vector<int> result;
    bool vis[n];

    for(int i = 0; i < n; i++) {
        vis[i] = false;
    }

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        graph[u].push_back(v);
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            DFS(graph, vis, st, i);
        }
    }

    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
    }

    return 0;
}