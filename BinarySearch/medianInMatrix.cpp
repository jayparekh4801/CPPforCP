#include <iostream>
#include <vector>

using namespace std;

int countLesser(vector<vector<int> > matrix, int r, int c, int val) {
    int result = 0;

    for(int i = 0; i < r; i++) {
        int high = c - 1;
        while(matrix[i][high] > val) {
            high--;
        }
        result += (high + 1);
    }

    return result;
}

int matrixMedian(vector<vector<int> > matrix, int r, int c) {
    int l = 1;
    int h = 1e+9;
    int bar = (r * c) / 2;

    while(l <= h) {
        int mid = (l + h) / 2;
        int les = countLesser(matrix, r, c, mid);

        if(les <= bar) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }

    // 1 2 3 3 5 6 6 9 9

    return l;
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

    int result = matrixMedian(matrix, r, c);
    cout << result;

    return 0;
}