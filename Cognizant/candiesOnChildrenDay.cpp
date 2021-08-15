#include <iostream>

using namespace std;

int findMaxReduce(int n, int k, int a[]) {
    sort(a, a + n);
    if(k == 0) {
        return a[n - 1];
    }
    else {
        return a[n - k];
    }
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = findMaxReduce(n, k, a);
    cout << result;

    return 0;
}