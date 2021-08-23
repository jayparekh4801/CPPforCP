#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int src, dest, weight;
}

struct Graph {
    int v, int e;
    struct Edge *edge;
}

Graph* createGraph(int v, int e) {
    struct Graph *graph = new Graph;
    graph -> v = v;
    graph -> e = e;
    graph -> edge = new Edge[e];
    return graph;
}

vector<pair<int, int> > bellamanFord(Graph* graph, int src) {
    vector<pair<int, int> > dist(graph -> v);

    for(int i = 0;i < vector.size(); i++) {
        dist[i].first = INT_MAX;
        dist[i].second = i;
    }

    dist[src].first = dist[src].second = 0;

    for(int i = 0; i < graph -> v - 1; i++) {
        for(int j = 0; j < graph -> e; j++) {
            int u = graph -> edge[j].src;
            int v = graph -> edge[j].dest;
            int w = graph -> edge[j].weight;

            if(dist[u] > )
        }
    }

}

int main() {

    int v = 5;
    int e = 8;

    struct Graph *graph = createGraph(v, e);

    graph -> edge[0].src = 0;
    graph -> edge[0].dest = 1;
    graph -> edge[0].weight = -1;

    graph -> edge[1].src = 0;
    graph -> edge[1].dest = 2;
    graph -> edge[1].weight = 4;

    graph -> edge[2].src = 1;
    graph -> edge[2].dest = 2;
    graph -> edge[2].weight = 3;

    graph -> edge[3].src = 1;
    graph -> edge[3].dest = 3;
    graph -> edge[3].weight = 2;

    graph -> edge[4].src = 1;
    graph -> edge[4].dest = 4;
    graph -> edge[4].weight = 2;

    graph -> edge[5].src = 3;
    graph -> edge[5].dest = 2;
    graph -> edge[5].weight = 5;

    graph -> edge[6].src = 3;
    graph -> edge[6].dest = 1;
    graph -> edge[6].weight = 1;

    graph -> edge[7].src = 4;
    graph -> edge[7].dest = 3;
    graph -> edge[7].weight = -3;

    return 0;
}