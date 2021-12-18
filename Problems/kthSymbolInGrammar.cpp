#include <iostream>

using namespace std;

int kthSymbol(int n, int k) {
    // vector<int> result;
    // result = findKthSymbol(n);
    // return result[k - 1];

    if(n == 1) {
        return 0;
    }
    int mid = pow(2, n - 1) / 2;

    if(k <= mid) {
        return kthSymbol(n - 1, k);
    }
    else {
        return !(kthSymbol(n - 1, k - mid));
    }
}

int main() {
    int n = 2;
    int k = 2;
    int result = kthSymbol(n, k);
    cout << result;
    return 0;
}