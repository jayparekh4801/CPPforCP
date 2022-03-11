#include <iostream>

using namespace std;

int findPos(int a[], int n, int target) {
   int l = 0;
   int r = n - 1;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == target) {
           return mid;
        }

        if(a[mid] >= a[l]) {
            if(target < a[mid] && target >= a[l]) {
               r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        else {
            if(target > a[mid] && target <= a[r]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n;
    int target;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> target;

    int result = findPos(a, n, target);
    cout << result;
    return 0;
}
