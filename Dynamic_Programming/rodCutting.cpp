#include <iostream>

using namespace std;

// using Recursive Approach 

// int profitOfRodCutting(int s[], int p[], int n, int l) {
//     if(n == 0 || l == 0) {
//         return 0;
//     }

//     if(s[n - 1] <= l) {
//         return max(p[n - 1] + profitOfRodCutting(s, p, n, l - s[n - 1]), profitOfRodCutting(s, p, n - 1, l));
//     }

//     else {
//         return profitOfRodCutting(s, p, n - 1, l);
//     }
// }

// using Dynamic Approach
int profitOfRodCutting(int s[], int p[], int n, int l) {
    int t[n + 1][l + 1];

    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < l + 1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < l + 1; j++) {
            if(s[i - 1] <= j) {
                t[i][j] = max(p[i - 1] + t[i][j - s[i -1]], t[i - 1][j]);
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][l];
}

int main() {
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int l = 8;
    int n = 8;
    int result = profitOfRodCutting(s, p, n, l);
    cout << result;
    return 0;
}