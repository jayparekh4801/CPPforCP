#include <iostream>

using namespace std;

int trappedRainWater(int a[], int n) {
    int result = 0;
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    int l = 0;
    int r = n - 1;

    while(l <= r) {
        if(a[l] <= a[r]) {
            if(a[l] > leftMax) {
                leftMax = a[l];
            }
            else {
                result += (leftMax - a[l]);
            }
            l++;
        }

        else {
            if(a[r] > rightMax) {
                rightMax = a[r];
            }
            else {
                result += (rightMax - a[r]);
            }
            r--;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = trappedRainWater(a, n);
    cout << result;
    return 0;
}