#include <iostream>
#include <vector>

using namespace std;

void allPaths(string path, int row, int col, vector<vector<int> > m, int n, vector<vector<int> > vis, vector<string>& result) {
    if(row == n - 1 && col == n - 1) {
        result.push_back(path);
        return;
    }

    if(row + 1 < n && m[row + 1][col] == 1 && vis[row + 1][col] == 0) {
        vis[row + 1][col] = 1;
        path += "D";
        allPaths(path, row + 1, col, m, n, vis, result);
        path.pop_back();
        vis[row + 1][col] = 0;
    }

    if(col - 1 >= 0 && m[row][col - 1] == 1 && vis[row][col - 1] == 0) {
        vis[row][col - 1] = 1;
        path += "L";
        allPaths(path, row, col - 1, m, n, vis, result);
        path.pop_back();
        vis[row][col - 1] = 0;
    }

    if(col+ 1 < n && m[row][col + 1] == 1 && vis[row][col + 1] == 0) {
        vis[row][col + 1] = 1;
        path += "R";
        allPaths(path, row, col + 1, m, n, vis, result);
        path.pop_back();
        vis[row][col + 1] = 0;
    }

    if(row - 1 >= 0 && m[row - 1][col] == 1 && vis[row - 1][col] == 0) {
        vis[row - 1][col] = 1;
        path += "U";
        allPaths(path, row - 1, col, m, n, vis, result);
        path.pop_back();
        vis[row - 1][col] = 0;
    }

}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > m;
    vector<vector<int> > vis;
    vector<string> result;
    string path = "";

    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        m.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            temp.push_back(0);
        }
        vis.push_back(temp);
    }

    if(m[0][0] != 0) {
        vis[0][0] = 1;
        allPaths(path, 0, 0, m, n, vis, result);
    }

    if(result.size() == 0) {
        cout << -1;
    }
    else {
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }

    return 0;
}