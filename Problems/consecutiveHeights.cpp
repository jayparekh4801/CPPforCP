#include <iostream>

using namespace std;
int addMinimum(int N, int A[], int k) {
    sort(A, A + N);
    int result = 0;
    for(int i = 0; i < N - 1; i++) {
        if(A[i + 1] - A[i] <= k) {
            continue;
        }
        else if(A[i + 1] == A[i] + 1) {
            return -1;
        }
        else {
            result++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int result = addMinimum(n, a, k);
    cout << result;
    return 0;
}