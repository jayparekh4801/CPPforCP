#include <iostream>

using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && a[l] > a[largest]) {
        largest = l;
    }

    if(r < n && a[r] > a[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {

    int startidx = (n / 2) - 1;

    for(int i = startidx; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

int main() {
    int a[] = {10, 20, 4, 5, 9, 30};
    int size = sizeof(a) / sizeof(a[0]);
    printArray(a, size);
    buildMaxHeap(a, size);
    printArray(a, size);
    return 0;
}