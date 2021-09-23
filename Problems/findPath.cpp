#include<iostream>


// array, maxstep is given and find maximu possible sum;
using namespace std;

int maxSum(int a[], int n) {
    if(n == 0) {
        return 0;
    }

    if(n < 2) {
        return a[n - 1];
    }

    return a[n - 1] + max(maxSum(a, n - 1), maxSum(a, n - 2));
}

int findMaxSum(int a[], int n, int maxstep) {
    int result = maxSum(a, n);
    return result;
}

int main() {
    int a[] = {10, -20, -5, 15};
    int n = 4;
    int maxStep = 2;
    int result = findMaxSum(a, n, maxStep);
    cout << result;
    return 0;
}