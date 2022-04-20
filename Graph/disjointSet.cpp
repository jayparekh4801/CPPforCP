#include <iostream>

using namespace std;

int parent[10000];
int rank[10000];

void makeSet(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int v) {
    if(v == parent[v]) {
        return v;
    }

    return parent[v] = findPar(par[v]);
}

void unionSet(int u, int v) {
    int u = findPar(u);
    int v = findPar(v);

    if(rank[u] > rank[v]) {
        parent[v] = u;
    }
    else if(rank[v] > rank[u]) {
        parent[u] = v;
    }
    else {
        parent[u] = v;
        rank[v]++;
    }
}

int main() {
    int v;
    cin >> v;

    makeSet(v);


    return 0;
}