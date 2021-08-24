#include <iostream>
#include <stack>
using namespace std;

void DFS(int grid[5][5], int i, int j, int row, int col) {
   if(i < 0 || j < 0 || i > row - 1 || j > col - 1 || grid[i][j] != 1) {
       return;
   }
   if(grid[i][j] == 1) {
       grid[i][j] = 0;
       DFS(grid, i - 1, j, row, col);
       DFS(grid, i - 1, j - 1, row, col);
       DFS(grid, i - 1, j + 1, row, col);
       DFS(grid, i, j - 1, row, col);
       DFS(grid, i, j + 1, row, col);
       DFS(grid, i + 1, j, row, col);
       DFS(grid, i + 1, j - 1, row, col);
       DFS(grid, i + 1, j + 1, row, col);
   }
}

int countIslands(int grid[5][5], int row, int col) {
    int islands = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j] == 1) {
                grid[i][j] = 0;
                islands++;
                DFS(grid, i - 1, j, row, col);
                DFS(grid, i - 1, j - 1, row, col);
                DFS(grid, i - 1, j + 1, row, col);
                DFS(grid, i, j - 1, row, col);
                DFS(grid, i, j + 1, row, col);
                DFS(grid, i + 1, j, row, col);
                DFS(grid, i + 1, j - 1, row, col);
                DFS(grid, i + 1, j + 1, row, col);
            }
        }
    }
    return islands;
}

int main() {
    int grid[5][5] = {{1, 1, 0, 0, 0},
                       {0, 1, 0, 0, 1},
                       {1, 0, 0, 1, 1},
                       {0, 0, 0, 0, 0},
                       {1, 0, 1, 0, 1}};

    int row = 5;
    int col = 5;

    int result = countIslands(grid, row, col);
    cout << result;
    return 0;
}