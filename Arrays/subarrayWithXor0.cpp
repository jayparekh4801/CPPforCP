#include <iostream>
#include <map>

using namespace std;

int kXorSubarray(int a[], int n, int k) {
    int xo = 0;
    int result = 0;
    map<int, int> m;

    for(int i = 0; i < n; i++) {
        xo ^= a[i];
        if(xo == k) {
            result++;
        }

        if(m.find(xo) == m.end()) {
            m.insert(make_pair(xo, 1));
        }
        else {
            m[xo]++;
        }

        if(m.find(xo ^ k) != m.end()) {
            result += m[xo ^ k];
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    int result = kXorSubarray(a, n, k);

    cout << result;

    return 0;
}