#include <iostream>
#include <queue>

using namespace std;

void heapsort(int a[], int n) {
    priority_queue<int, vector<int>, greater<int> > min_heap;

    for(int i = 0; i < n; i++) {
        min_heap.push(a[i]);
    }

    for(int i = 0; !min_heap.empty(); i++) {
        a[i] = min_heap.top();
        min_heap.pop();
        
    }
}

void printArray(int a[], int n) {

    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

int main() {
    int a[] = {20, 10, 5, 8, 9, 17, 4, 7};
    int size = sizeof(a) / sizeof(a[0]);
    printArray(a, size);
    heapsort(a, size);
    cout << "\n";
    printArray(a, size);
    return 0;
}