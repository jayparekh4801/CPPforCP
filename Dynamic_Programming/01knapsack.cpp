#include <iostream>

using namespace std;


int t[100][100];
    
int knapsack(int w[], int v[], int n, int wk) {
    if(n == 0 || wk == 0) {
        return 0;
    }

    if(t[n][wk] != -1) {
        return t[n][wk];
    }

    if(w[n - 1] <= wk) {
        return t[n][wk] = max(v[n - 1] + knapsack(w, v, n - 1, wk - w[n - 1]), knapsack(w, v, n - 1, wk));
    }

    else {
        return t[n][wk] = knapsack(w, v, n - 1, wk);
    }
}

int main() {
    int w[4] = {1, 3, 4, 5};
    int v[4] = {1, 4, 5, 7};
    int n = 4;
    int wk = 7;
    t, memset(t, -1, sizeof(t));


    int result = knapsack(w, v, n, wk);
    cout << result;

    
    return 0;
}