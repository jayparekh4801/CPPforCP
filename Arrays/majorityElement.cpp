#include <iostream>

using namespace std;

int majorityElement(int a[], int n) {
    int result = -1;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            result = a[i];
        }

        if(result == a[i]) {
            count++;
        }

        else {
            count--;
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

    int result = majorityElement(a, n);
    cout << result;

    return 0;
}