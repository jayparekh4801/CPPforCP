// Problem Statment :- Sort Array Using Recursion

#include <iostream>

using namespace std;

void putInPlace(int a[], int n) {
    if(n == 1) {
        return;
    }
    if(a[n - 1] < a[n - 2]) {
        swap(a[n - 1], a[n - 2]);
        putInPlace(a, n - 1);
    }
}

void sortRecursion(int a[], int n) {
    if(n == 1) {
        return;
    }

    sortRecursion(a, n - 1);
    putInPlace(a, n);
}


int main() {
    int a[] = {2, 5, 4, 1, 7};
    int n = 5;
    sortRecursion(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}