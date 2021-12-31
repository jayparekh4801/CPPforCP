#include <iostream>

using namespace std;

int LCS(string s1, string s2, int n, int m, string& result) {
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
                cout << s2[j - 1];
            }
            else {
                t[i][j] = max(t[i][j - 1] , t[i - 1][j]);
            }
        }
    }

    return t[n][m];
}

int main() {
    string s1 = "geeks";
    string s2 = "geeksfor";
    string s3 = "geeksforgeeks";
    int n1 = 5;
    int n2 = 8;
    int n3 = 13;
    string result = "";
    int n = LCS(s1, s2, n1, n2, result);
    // cout << result << " " << n;
    cout << n;

    return 0;
}