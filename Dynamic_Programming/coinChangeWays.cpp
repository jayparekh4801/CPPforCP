#include <iostream>

using namespace std;

// Recursive Approach
// int findWays(int a[], int n, int c) {
//     if(n == 0 && c == 0) {
//         return 1;
//     }
//     if(n == 0) {
//         return 0;
//     }
//     if(c == 0) {
//         return 1;
//     }

//     if(a[n - 1] <= c) {
//         return findWays(a, n, c - a[n - 1]) + findWays(a, n - 1, c);
//     }

//     else {
//         return findWays(a, n - 1, c);
//     }
// }

// Dynamic Approach
int findWays(int coins[], int numberOfCoins, int value){
    long long int t[numberOfCoins + 1][value + 1];
    for (int i = 0; i < numberOfCoins + 1; i++) {
        for (int j = 0; j < value + 1; j++) {
            if (i == 0) {
                t[i][j] = 0;
            }

            if (j == 0) {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < numberOfCoins + 1; i++) {
        for (int j = 1; j < value + 1; j++) {
            if (coins[i - 1] <= j) {
                t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[numberOfCoins][value];
}

int main()
{
    int a[] = {1, 2};
    int c = 4;
    int n = 2;

    int result = findWays(a, n, c);
    cout << result;
    return 0;
}