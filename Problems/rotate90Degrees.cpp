#include <iostream>

using namespace std;

void printMatrix(int **a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

void rotate90Degrees(int **a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(a[i][j], a[j][i]);
        }
    }
    
    for(int i = 0; i < n; i++) {
        reverse(a[i], a[i] + n);
    }
}

int main() {
    int n = 3;
    int c = 1;
    int **a;
    a = new int* [n];
    a[0] = new int[n];
    a[1] = new int[n];
    a[2] = new int[n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = c;
            c++;
        }
    }
    printMatrix(a, n);
    rotate90Degrees(a, n);
    printMatrix(a, n);
    return 0;
}