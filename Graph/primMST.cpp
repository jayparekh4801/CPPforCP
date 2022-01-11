#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void primsMST(vector<pair<int, int> >graph[], int v, int src, int val[], bool mst[], int par[]) {

    val[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    
    for(int count = 0; count < v - 1; count++) {
        int mini = pq.top().second;
        pq.pop();
        mst[mini] = true;

        for(int i = 0; i < graph[mini].size(); i++) {
            if(mst[graph[mini][i].first] == false && val[graph[mini][i].first] > graph[mini][i].second) {
                par[graph[mini][i].first] = mini;
                pq.push(make_pair(val[graph[mini][i].first], graph[mini][i].first));
                val[graph[mini][i].first] = graph[mini][i].second;
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    int val[v];
    bool mst[v];
    int par[v];
    int src;
    vector<pair<int, int> > graph[v];

    for(int i = 0; i < v; i++) {
        val[i] = INT_MAX;
        mst[i] = false;
        par[i] = -1;
    }

    for(int i = 0; i < e; i++) {
        int v, u, w;

        cin >> v;
        cin >> u;
        cin >> w;

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    cin >> src;

    primsMST(graph, v, src, val, mst, par);

    for(int i = 0; i < v; i++) {
        cout << i << " joints with " << par[i] << " with value " << val[i] << "\n";
    }

}