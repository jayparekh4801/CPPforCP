#include <iostream>

using namespace std;

void merge(int a[], int s, int m, int e) {
    int b[e - s + 1];
    int i = s;
    int j = m;
    int k = 0;
    while(i < m && j <= e) {
        if(a[i] <= a[j]) {
            b[k] = a[i];
            k++;
            i++;
        }

        else {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while(i < m) {
        b[k] = a[i];
        i++;
        k++;
    }

    while(j <= e) {
        b[k] = a[j];
        j++;
        k++;
    }

    for(i = s, k = 0; i <= e; i++, k++) {
        a[i] = b[k];
    }
}

void mergeSort(int a[], int s, int e) {
    if(s < e) {
        int mid = s + (e - s) / 2;
        mergeSort(a, s, mid);
        mergeSort(a, mid + 1, e);
        merge(a, s, mid + 1, e);
    }   
    return;
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

int main() {
    int a[] = {10, 9, 7, 11, 12, 5, 3};
    mergeSort(a, 0, 6);
    printArray(a, 7);
    return 0;
}