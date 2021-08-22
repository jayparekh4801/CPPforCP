#include <iostream>

using namespace std;

int LCS(string s1, string s2, int n, int m) {
    if(n == 0 || m == 0) {
        return 0;
    }

    if(s1[n - 1] == s2[m - 1]) {
        return 1 + LCS(s1, s2, n - 1, m - 1);
    }
    else {
        return max(LCS(s1, s2, n - 1, m), LCS(s1, s2, n, m - 1));
    }

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