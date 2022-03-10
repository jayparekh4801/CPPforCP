#include <iostream>

using namespace std;

int singleEle(int a[], int n) {
    int l = 0; 
    int h = n - 2;

    while(l <= h) {
        int mid = (l + h) / 2;

        if(a[mid] == a[mid ^ 1]) {
            l = mid + 1;

        }
        else {
            h = mid - 1;

        }
    }

    return a[l];
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = singleEle(a, n);
    cout << result;

    return 0;
}