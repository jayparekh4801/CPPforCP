#include <iostream>

using namespace std;

int isSubset(int a[], int n, int s) {
    if(n == 0 || s == 0) {
        return 0;
    }

    if(a[n - 1] <= s) {
        return max(a[n - 1] + isSubset(a, n - 1, s - a[n -1]), isSubset(a, n - 1, s));
    }
    else {
        return isSubset(a, n - 1, s);
    }

}

int main() {
    int a[] = {2, 3, 7, 8, 10};
    int s = 14;

    int result = isSubset(a, 5, s);
    if(result == s) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}