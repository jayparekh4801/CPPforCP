#include <iostream>

using namespace std;

int  fibonacci(int n) {
    int result;
    if(n == 0 || n == 1) {
        return n;
    }

    return result = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;

    int result = fibonacci(n);
    return 0;
}