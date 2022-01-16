#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isInside(int nx, int ny, int N) {
    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
        return true;
    }
    return false;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N) {
    queue<pair<pair<int, int>, int> > q;
    bool vis[N + 1][N + 1];
    int dx[] = {-2, -1, 1, 2, -1, 1, 2, -2};
    int dy[] = {-1, -2, -2, -1, 2, 2, 1, 1};

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            vis[i][j] = false;
        }
    }

    vis[KnightPos[0]][KnightPos[1]] = true;
    q.push(make_pair(make_pair(KnightPos[0], KnightPos[1]), 0));

    while (!q.empty()) {
        pair<pair<int, int>, int> temp = q.front();
        q.pop();
        int x = temp.first.first;
        int y = temp.first.second;
        int dis = temp.second;

        if (x == TargetPos[0] && y == TargetPos[1]) {
            return dis;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isInside(nx, ny, N) && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), dis + 1));
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> knightPos;
    vector<int> targetPos;
    int kpi;
    int kpf;
    cin >> kpi;
    cin >> kpf;
    knightPos.push_back(kpi);
    knightPos.push_back(kpf);
    int tpi;
    int tpf;
    targetPos.push_back(tpi);
    targetPos.push_back(tpf);
    int result =  minStepToReachTarget(knightPos, targetPos, N);

    cout << result;

    return 0;
}