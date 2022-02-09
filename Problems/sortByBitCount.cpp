#include <iostream>

using namespace std;

int countBits(int n) {
    int result = 0;

    while(n) {
        if(n & 1) {
            result++;
        }
        n >>= 1;
    }

    return result;
}

bool cmp(int a, int b) {
    int a1 = countBits(a);
    int b1 = countBits(b);

    if(a1 <= b1) {
        return false;
    }
    return true;
}

void sortBySetBit(int arr[], int n) {
    stable_sort(arr, arr + n, cmp);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortBySetBit(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

}