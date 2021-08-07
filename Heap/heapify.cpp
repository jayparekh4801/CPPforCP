#include <iostream>

using namespace std;

#define MAX 1000

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

void deleteRoot(int a[], int &n) {
    a[0] = a[n -1];
    n = n - 1;

    heapify(a, n, 0);
}

void insertNode(int a[], int &n, int key) {
    n = n + 1;
    a[ n - 1] = key;
    buildMaxHeap(a, n);
}

int main() {
    int a[MAX] = {10, 5, 3, 2, 4};
    // int size = sizeof(a) / sizeof(a[0]);
    int size = 5;
    printArray(a, size);
    // buildMaxHeap(a, size);
    deleteRoot(a, size);
    cout<<"\n";
    printArray(a, size);
    insertNode(a, size, 20);
    cout << "\n";
    printArray(a, size + 1);
    
    return 0;
}