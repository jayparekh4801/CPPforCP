#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void addEdge(vector<int> g[], int s, int d) {
    g[s].push_back(d);
    g[d].push_back(s); 
}

void BFS(vector<int> g[], int v) {
    bool visited[v + 1];
    int s = 1;

    for(int i = 0; i <= v; i++) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int temp = q.front();
        cout << temp << "\t";
        q.pop();
        for(int i = 0; i < g[temp].size(); i++) {
            if(visited[g[temp][i]] == false) {
                visited[g[temp][i]] = true;
                q.push(g[temp][i]);
            }
        }
    }
}

void DFS(vector<int> g[], int v) {
    int visited[v + 1];
    int s = 1;
    stack<int> st;
    st.push(s);
    
    for(int i = 0; i <= v; i++) {
        visited[i] = false;
    }

    visited[s] = true;

    while (!st.empty()){
        int temp = st.top();
        cout << temp << "\t";
        st.pop();

        for(int i = 0; i < g[temp].size(); i++) {
            if(visited[g[temp][i]] == false) {
                visited[g[temp][i]] = true;
                st.push(g[temp][i]);
            }
        }
    }
}

int main() {
    int v = 6;
    vector<int> g[v + 1];
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 5);
    addEdge(g, 2, 4);
    addEdge(g, 3, 5);
    addEdge(g, 4, 5);
    addEdge(g, 4, 6);
    addEdge(g, 5, 6);
    BFS(g, v);
    cout << "\n";
    DFS(g, v);
    return 0;
}