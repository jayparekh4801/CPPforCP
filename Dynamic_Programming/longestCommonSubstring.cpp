#include <iostream>

using namespace std;

int LCSubstring(string s1, string s2, int n, int m) {
    int result = 0;
    int t[n + 1][m + 1];
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < m + 1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
                result = max(result, t[i][j]);
            }
            else {
                t[i][j] = 0;
            }
        }
    }

    return result;
}

int main() {
    string s1 = "abcdgh";
    string s2 = "abedfhr";
    int n = 6;
    int m = 7;

    int result = LCSubstring(s1, s2, n, m);
    cout << result;

    return 0;
}