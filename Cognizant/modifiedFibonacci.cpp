#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 1, c;
    for(int i = 0; i < n - 2; i++) {
        c = a + b * b;
        
        a = b;
        b = c;
    }
    cout << c;
    return 0;
}