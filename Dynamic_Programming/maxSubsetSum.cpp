#include <iostream>

using namespace std;

// recursive approach

// int findMaxSum(int a[], int n) {
//     if(n == 0) {
//         return 0;
//     }

//     return max(a[n - 1] + findMaxSum(a, n - 1), findMaxSum(a, n -1));
// }


// dynamic approach

int findMaxSum(int a[], int n) {
    int t[n + 1];
    t[0] = 0;

    for(int i = 1; i < n + 1; i++) {
        t[i] = max(a[i - 1] + t[i - 1], t[i - 1]);
    }

    return t[n];
}

int main() {
    int a[] = {1, -2, 3, -4};
    int n = 4;

    int result = findMaxSum(a, n);
    cout << result;
    return 0;
}