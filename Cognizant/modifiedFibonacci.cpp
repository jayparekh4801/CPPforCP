#include <iostream>

using namespace std;

int main() {
    int n;
    int a = 0, b = 1, c;
    cin >> a;
    cin >> b;
    cin >> n;
    for(int i = 0; i < n - 2; i++) {
        c = a + b * b;
        
        a = b;
        b = c;
    }
    cout << c;
    return 0;
}