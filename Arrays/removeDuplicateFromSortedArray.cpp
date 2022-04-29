#include <iostream>

using namespace std;

int removeDuplicates(int a[], int n) {
    int i = 0;

    for(int j = 1; j < n; j++) {
        if(a[j] != a[i]) {
            i++;
            a[i] = a[j];
        }
    }

    return i + 1;
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = removeDuplicates(a, n);

    for(int i = 0; i < result; i++) {
        cout << a[i] << " ";
    }

    return 0;
}