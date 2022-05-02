#include <iostream>

using namespace std;

int maxConsecutiveOnes(int a[], int n) {
    int result = INT_MIN;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            count++;
        }

        else {
            result = max(result, count);
            count = 0;
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

    int result = maxConsecutiveOnes(a, n);

    cout << result;
    return 0;
}