#include <iostream>
#include <vector>

using namespace std;

bool findInMatrix(vector<vector<int> > matrix, int target, int r, int c) {
    int i = 0;
    int j = c - 1;

    while(i < n && j >= 0) {
        if(matrix[i][j] == target) {
            return true;
        }

        else if(matrix[i][j] > target) {
            j--;
        }
        
        else {
            i++;
        }
    }

    return false;
}

int main() {
    int r;
    int c;
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

    int target;
    cin >> target;

    bool result = findInMatrix(matrix, target, int r, int c);
    cout << result;
    return 0;
}