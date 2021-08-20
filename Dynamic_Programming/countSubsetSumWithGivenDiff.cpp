#include <iostream>

using namespace std;

int noOfSubsetsWithGivenSum(int a[], int n, int s) {
    int t[n + 1][s + 1];

    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < s + 1; j++) {
            if(i == 0) {
                t[i][j] = 0;
            }

            if(j == 0) {
                t[i][j] = 1;
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < s + 1; j++) {
            if(a[i - 1] <= j) {
                t[i][j] = t[i - 1][j - a[i - 1]] + t[i - 1][j];
            }

            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][s];
}

int noOfSubsetsumWithGivenDiff(int a[], int n, int diff) {
    int sum = 0;
    int s1;

    for(int i = 0; i < n; i++) {
        sum += a[i];
    }

    if((sum + diff) % 2 != 0) {
        return 0;
    } 

    s1 = (sum + diff) / 2;
    
    int count = noOfSubsetsWithGivenSum(a, n, s1);
    return count;

}

int main() {
    int a[] = {1, 1, 2, 3};
    int n = 4;
    int diff = 1;

    int result = noOfSubsetsumWithGivenDiff(a, n, diff);
    cout << result;
    return 0;
}