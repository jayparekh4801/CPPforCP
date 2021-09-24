#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int lengthOfStringWithUniqueChars(string s) {
    vector<int> t(256, -1);
    int l = 0;
    int r = 0;
    int maxLen = 0;

    while(r < s.length()) {
        if(t[s[r]] != -1) {
            if(t[s[r]] + 1 > l) {
                l = t[s[r]] + 1;
            }
        }
        t[s[r]] = r;
        if(r - l + 1 > maxLen) {
            maxLen = r - l + 1;
        }
        r++;
    }
    return maxLen;
}

int main() {
    string s = "abdefgabef";
    int result = lengthOfStringWithUniqueChars(s);
    cout << result;
    return 0;
}