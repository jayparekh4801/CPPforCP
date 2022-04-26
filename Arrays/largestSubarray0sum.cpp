#include <iostream>
#include <map>

using namespace std;

int largestSubarray(int a[], int n) {
    map<int, int> m;
    int s = 0;
    int result = 0;

    for(int i = 0; i < n; i++) {
        s += a[i];

        if(s == 0) {
            result = max(result, i + 1);
        }

        else {
            if(m.find(s) == m.end()) {
                m.insert(make_pair(s, i));
            }
            else {
                int cl = i - m[s];
                result = max(cl, result);
            }
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

    int result = largestSubarray(a, n);

    cout << result;

    return 0;
}