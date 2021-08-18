#include <iostream>
#include <vector>

using namespace std;

bool isSubsetsum(int a[], int n, int s) {
    bool t[n + 1][s + 1];

    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < s + 1; j++) {
            if(i == 0) {
                t[i][j] = false;
            }
            if(j == 0) {
                t[i][j] = true;
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < s + 1; j++) {
            if(a[i - 1] <= j) {
                t[i][j] = t[i - 1][j - a[i -1]] || t[i - 1][j];
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][s];
}

int findMinDiff(int a[], int n) {
    int min = INT_MAX;
    int sum = 0;
    vector<int> v;

    for(int i = 0; i < n; i++) {
        sum += a[i];
    }

    for(int i = 0; i <= sum; i++) {
        if(isSubsetsum(a, n, i)) {
            v.push_back(i);
        }
    }

    for(int i = 0; i < v.size(); i++) {
        if(abs(sum - 2 * v[i]) < min) {
            min = abs(sum - 2 * v[i]);
        }
    }

    return min;
}

int main() {
    int a[] = {1, 5, 11, 6};
    int n = 4;

    int result = findMinDiff(a, n);
    cout << result;
    return 0;
}