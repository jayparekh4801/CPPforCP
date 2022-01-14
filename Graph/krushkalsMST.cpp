#include <iostream>
#include <vector>

using namespace std;

int parent[10000];
int ranks[10000];

void makeSet(int n) {
    for(int i = 0; i < n; i++) {
        ranks[i] = 0;
        parent[i] = i;
    }
}

int findPar(int node) {
    if(node == parent[node]) {
        return node;
    }

    return parent[node] = findPar(node);
}

void unionSet(int u, int v) {
    u = findPar(u);
    v = findPar(v);

    if(ranks[u] > ranks[v]) {
        parent[v] = u;
    }
    else if(ranks[v] > ranks[u]) {
        parent[u] = v;
    }
    else {
        parent[v] = u;
        ranks[u]++;
    }
}

bool sortByWt(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
    return a.first < b.first;
} 

int krushkal(vector<pair<int, int> > graph[], int v) {
    vector<pair<int, pair<int, int> > > edges;
    int result = 0;

    for(int i = 0; i < v; i++) {
        for(pair<int, int>  it : graph[i]) {
            pair<int, pair<int, int> > temp;
            pair<int, int> tpair;
            tpair.first = i;
            tpair.second = it.first;
            temp.first = it.second;
            temp.second = tpair;
            edges.push_back(temp);
        }
    }

    sort(edges.begin(), edges.end(), sortByWt);

    for(pair<int, pair<int, int> > edge : edges) {
        if(findPar(edge.second.first) != findPar(edge.second.second)) {
            result += edge.first;
            unionSet(edge.second.first, edge.second.second);
        }
    }

    return result;
}

int main() {
    int v, e;
    cin >> v >> e;

    makeSet(v);

    vector<pair<int , int> > graph[v];
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int result = krushkal(graph, v);
    cout << result;
    return 0;
}