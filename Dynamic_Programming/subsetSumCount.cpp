#include <iostream>

using namespace std;

int countOfSubsetSum(int a[], int n, int s) {
    if(n == 0 && s == 0) {
        return 1;
    }

    else if(n == 0) {
        return 0;
    }

    else if(s == 0) {
        return 1;
    }

    if(a[n - 1] <= s){
        return countOfSubsetSum(a, n - 1, s - a[n - 1]) + countOfSubsetSum(a, n - 1, s);
    }
    else {
        return countOfSubsetSum(a, n - 1, s);
    }
    
}

int main() {
    int a[] = {2, 3, 5, 6, 8, 10};
    int s = 10;

    int result = countOfSubsetSum(a, 6, 10);
    cout << result;

    return 0;
}