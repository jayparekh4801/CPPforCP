#include <iostream>
#include <vector>

using namespace std;

void setMatrixZeros(vector<vector<int> >& matrix, int r, int c) {
    int col0 = 1;

    for(int i = 0; i < r; i++) {
        if(matrix[i][0] == 0) col0 = 0;

        for(int j = 1; j < c; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for(int i = r - 1; i >= 0; i--) {
        for(int j = c - 1; j >= 1; j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }

        if(col0 == 0) matrix[i][0] = 0;
    }
}

void printMatrix(vector<vector<int> > matrix, int r, int c) {
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int r, c;
    cin >> r;
    cin >> c;
    vector<vector<int> > matrix;

    for(int i = 0; i < r; i++) {
        vector<int> temp;
        for(int j = 0; j < c; j++) {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        matrix.push_back(temp);
    }

    setMatrixZeros(matrix, r, c);
    printMatrix(matrix, r, c);
    
    return 0;
}