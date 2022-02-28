#include <iostream>

using namespace std;

int MCM(int a[], int i, int j) {
    if(i >= j) {
        return 0;
    }

    int ans = INT_MAX;

    for(int k = i; k <= j - 1; k++) {
        int tempans = MCM(a, i, k) + MCM(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        if(tempans < ans) {
            ans = tempans;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = MCM(a, 1, n - 1);
    cout << result;

    return 0;
}