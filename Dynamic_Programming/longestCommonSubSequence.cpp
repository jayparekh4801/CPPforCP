#include <iostream>

using namespace std;

// Recursive Approach

// int LCS(string s1, string s2, int n, int m) {
//     if(n == 0 || m == 0) {
//         return 0;
//     }

//     if(s1[n - 1] == s2[m - 1]) {
//         return 1 + LCS(s1, s2, n - 1, m - 1);
//     }
//     else {
//         return max(LCS(s1, s2, n - 1, m), LCS(s1, s2, n, m - 1));
//     }

// }

// Dynamic Approach
int LCS(string s1, string s2, int n, int m) {
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
            }
            else {
                t[i][j] = max(t[i][j - 1] , t[i - 1][j]);
            }
        }
    }

    return t[n][m];
}

int main() {
    string s1 = "abcdgh";
    string s2 = "abedfhr";
    int n = 6;
    int m = 7;

    int result = LCS(s1, s2, n, m);
    cout << result;
    return 0;
}