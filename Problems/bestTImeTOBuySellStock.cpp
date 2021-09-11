#include <iostream>
#include <cmath>

using namespace std;

int bestTimeForStock(int a[], int n) {
    int min = INT_MAX;
    int profit = 0;
    
    for(int i = 0; i < n; i++) {
        if(a[i] < min) {
            min = a[i];
        }
        if(a[i] - min > profit) {
            profit = a[i] - min;
        }
    }

    return profit;
}

int main() {
    int a[] = {7, 1, 5, 3, 6, 4};
    int n = 6;
    int result = bestTimeForStock(a, n);
    cout << result;
    return 0;
}