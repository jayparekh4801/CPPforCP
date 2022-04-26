#include <iostream>

using namespace std;

int merge(int nums[], int l, int mid, int r) {
    int result = 0;
    int j = mid + 1;
    for(int i = l; i <= mid; i++) {
        while(j <= r && nums[i] > 2 * nums[j]) {
            j++;
        }
        result += (j - (mid + 1));
    }

    int b[r - l + 1];
    int i = l;
    j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r) {
        if(nums[i] <= nums[j]) {
            b[k] = nums[i];
            i++;
            k++;
        }

        else {
            b[k] = nums[j];
            j++;
            k++;
        }
    }

    while(i <= mid) {
        b[k] = nums[i];
        i++;
        k++;
    }

    while(j <= r) {
        b[k] = nums[j];
        k++;
        j++;
    }

    for(i = l, k = 0; i <= r; i++, k++) {
        nums[i] = b[k];
    }

    return result;
}

int mergeSort(int a[], int l, int r) {
    int result = 0;
    if(l < r) {
        int mid = (l + r) / 2;
        result += mergeSort(a, l, mid);
        result += mergeSort(a, mid + 1, r);
        result += merge(a, l, mid, r);
    }    

    return result;   
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int l = 0;
    int r = n - 1;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = mergeSort(a, l, r);

    cout << result;
    return 0;
}