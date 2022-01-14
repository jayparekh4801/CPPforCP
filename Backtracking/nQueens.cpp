#include <iostream>
#include <vector>

using namespace std;

bool isValid(int col, int row, vector<string> board, int n) {
    int dcol = col;
    int drow = row;

    while(dcol >= 0 && drow >= 0) {
        if(board[drow][dcol] == 'Q') return false;
        dcol--;
        drow--;
    }

    dcol = col;
    drow = row;

    while(dcol >= 0) {
        if(board[drow][dcol] == 'Q') return false;
        dcol--;
    }

    dcol = col;
    drow = row;

    while(dcol >= 0 && drow < n) {
        if(board[drow][dcol] == 'Q') return false;
        dcol--;
        drow++;
    }

    return true;


}

void solve(int col, vector<string>& board, vector<vector<int> >& result, vector<int>& co, int n) {
    if(col == n) {
        result.push_back(co);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isValid(col, row, board, n)) {
            board[row][col] = 'Q';
            co.push_back(row + 1);
            solve(col + 1, board, result, co, n);
            board[row][col] = '.';
            co.pop_back();
        }
    }
}

vector<vector<int> > queenWays(int n) {
    vector<vector<int> > result;
    vector<int> co;
    vector<string> board(n); 
    string s(n, '.');

    for(int i = 0; i < n; i++) {
        board[i] = s;
    }

    solve(0, board, result, co, n);
    return result;
}

int main() {
    int n;
    
    cin >> n;

    vector<vector<int> >  result = queenWays(n);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}