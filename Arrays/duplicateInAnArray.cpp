#include <iostream>


using namespace std;

int findDuplicate(int a[], int n) {
    int slow = a[0];
    int fast = a[0];

    do {
        slow = a[slow];
        fast = a[a[fast]];
    }while(slow != fast);

    fast = a[0];

    while(slow != fast) {
        slow = a[slow];
        fast = a[fast];
    }

    return slow;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = findDuplicate(a, n);
    cout << result;
    return 0;
}