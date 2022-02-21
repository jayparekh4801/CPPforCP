#include <iostream>
#include <set>

using namespace std;

int longestConsecutiveSequence(int a[], int n) {
    set<int> s;
    int result = 0;

    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
    }

    for(int i = 0; i < n; i++) {
        if(s.find(a[i] - 1) == s.end()) {
            int count = 1;
            int val = a[i];
            while(s.find(val + 1) != s.end()) {
                count++;
                val++;
            }

            result = max(result, count);
        }
    }

    return result;
}

int main() {
    int a[] = {102, 4, 100, 1, 101, 3, 2};
    int n = 7;
    int result = longestConsecutiveSequence(a, n);
    cout << result;

    return 0;
}