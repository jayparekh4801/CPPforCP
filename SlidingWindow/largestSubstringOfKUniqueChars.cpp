#include <iostream>
#include <map>

using namespace std;

int largestSubstrOfKChars(string s, int k) {
    int l = 0;
    int r = 0;
    int maxLen = 0;
    map<char, int> m;

    while(r < s.length()) {
        if(m.find(s[r]) == m.end()) {
            m.insert(make_pair(s[r], 1));
        }
        else {
            m[s[r]]++;
        }

        if(m.size() == k) {
            if(r - l + 1 > maxLen) {
                maxLen = r - l + 1;
            }
        }

        if(m.size() > k) {
            while(m.size() > k) {
                if(m[s[l]] == 1) {
                    m.erase(s[l]);
                }
                else {
                    m[s[l]]--;
                }
                l++;
            }
        }
        r++;
    }

    return maxLen;
}

int main() {
    string s = "aabaccab";
    int k = 2;
    int result = largestSubstrOfKChars(s, k);
    cout << result;
    return 0;
}