#include <iostream>

using namespace std;

void TOH(int n, int s, int e, int a, int w, int& g) {
    if(n == 1) {
        if(g == w) {
            cout << s << " " << e << "\n";
        }
        g++;
        return;
    }

    TOH(n - 1, s, a, e, w, g);
    if(g == w) {
        cout << s << " " << e << "\n";
    }
    g++;
    TOH(n - 1, a, e, s, w, g);
}

int main() {
    int n;
    cin >> n;
    int g = 1;
    TOH(n, 1, 3, 2, 3, g);
    return 0;
}