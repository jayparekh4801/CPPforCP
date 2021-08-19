#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<pair <int , int> > graph[], int u, int v, int wt) {
    graph[u].push_back(make_pair(v, wt));
    graph[v].push_back(make_pair(u, wt));
}

vector<pair<int, int> > shortestPath(vector<pair <int, int> > graph[], int v, int src) {
    vector<pair<int , int> > dist(v);
    for(int i = 0; i < v; i++) {
        dist[i].first = INT_MAX;
        dist[i].second = i;
    }  

    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int , int> > > p;
    p.push(make_pair(0, src));
    dist[src].first = dist[src].second = 0;

    while(!p.empty()) {
        int temp = p.top().second;
        p.pop();

        for(int i = 0; i < graph[temp].size(); i++) {
            int v = graph[temp][i].first;
            int weight = graph[temp][i].second;
            if(dist[v].first > dist[temp].first + weight) {
                dist[v].first = dist[temp].first + weight;
                dist[v].second = temp;
                p.push(make_pair(dist[v].first, v));
            }

        }

    }

    return dist;

}

int main() {
    int v = 9;
    vector<pair <int, int> > graph[v];
    addEdge(graph, 0, 1, 4); 
    addEdge(graph, 0, 7, 8); 
    addEdge(graph, 1, 2, 8); 
    addEdge(graph, 1, 7, 11); 
    addEdge(graph, 2, 3, 7); 
    addEdge(graph, 2, 8, 2); 
    addEdge(graph, 2, 5, 4); 
    addEdge(graph, 3, 4, 9); 
    addEdge(graph, 3, 5, 14); 
    addEdge(graph, 4, 5, 10); 
    addEdge(graph, 5, 6, 2); 
    addEdge(graph, 6, 7, 1); 
    addEdge(graph, 6, 8, 6); 
    addEdge(graph, 7, 8, 7); 
    vector<pair<int, int> > result = shortestPath(graph, v, 0);
    for(int i = 0; i < v; i++) {
        cout << i<<" ancesotr "<< result[i].second << " weight " << result[i].first << "\n";
    }
    return 0;
}