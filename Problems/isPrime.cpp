#include <iostream>

using namespace std;

bool isPrime(int n) {
    int l = ceil(sqrt(n));

    if(n == 2) {
        return true;
    }

    for(int i = 2; i <= l; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    cin >> n;
    bool result = isPrime(n);

    if(result) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}