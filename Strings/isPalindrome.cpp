#include <iostream>

using namespace std;

static bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;
    bool result = true;

    while (l < r) {
        if (s[l] != s[r]) {
            result = false;
            break;
        }
        l++;
        r--;
    }

    return result;
}

int main() {
    string b = "aabbaa";
    bool result = isPalindrome(b);
    cout << result;
    return 0;
}