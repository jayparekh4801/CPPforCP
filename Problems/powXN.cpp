#include <iostream>

using namespace std;

double power(double x, int n) {
    double result = 1.0;
    int ne = n;

    if(n < 0) {
        n = -1 * n;
    }

    while(n > 0) {
        if(n % 2 == 0) {
            x = x * x;
            n = n / 2; 
        }

        else {
            result = result * x;
            n = n - 1;
        }
    }

    if(ne < 0) {
        result = (double)1 / (double)result;
    }

    return result;
}

int main() {
    int n;
    double x;

    cin >> x;
    cin >> n;
    double result = power(x, n);
    cout << "\n" << result;
    return 0;
}