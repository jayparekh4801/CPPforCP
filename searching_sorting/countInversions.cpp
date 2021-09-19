#include <iostream>

using namespace std;


int merge(int a[], int s, int m, int e) {
    int b[e - s + 1];
    int i = s;
    int j = m;
    int k = 0;
    int result = 0;

    while(i < m && j <= e) {
        if(a[i] <= a[j]) {
            i++;
        }

        else if(a[i] > 2 * a[j]) {
            j++;
            result += (m - i);
        }
        else {
            i++;
        }
    }

    i = s;
    j = m;

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
            // result += (m - i);
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
    return result;
}

int mergeSort(int a[], int s, int e) {
    int result = 0;
    if(s < e) {
        int mid = (s + e) / 2;
        result += mergeSort(a, s, mid);
        result += mergeSort(a, mid + 1, e);
        result += merge(a, s, mid + 1, e);
    }   
    return result;
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

int main() {
    int a[] = {40, 25, 19, 12, 9, 6, 2};
    int result = mergeSort(a, 0, 6);
    // printArray(a, 7);
    cout << result;
    return 0;
}