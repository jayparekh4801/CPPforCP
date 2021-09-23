#include <iostream>
#include <map>

using namespace std;

int minimumWindowSubstr(string s1, string s2) {
    map<char, int> m;
    int dc = 0;
    int l = 0;
    int r = 0;
    int minLen = INT_MAX;

    for(int i = 0; i < s2.length(); i++) {
        if(m.find(s2[i]) == m.end()) {
            m.insert(make_pair(s2[i], 1));
        }
        else {
            m[s2[i]]++;
        }
    }

    dc = m.size();

    while(m.find(s1[r]) == m.end()) {
        r++;
        l++;
    }

    while(r < s1.length()) {

        if(m[s1[r]] == 1) {
            dc--;
            m[s1[r]]--;
        }
        else {
            m[s1[r]]--; 
        }

        if(dc == 0) {
            if(r - l + 1 < minLen) {
                minLen = r - l + 1;
            }
            m[s1[l]]++;
            dc++;
            l++;

            while(m.find(s1[l]) == m.end()) {
                l++;
            }
            

        }
        r++;

    }

    return minLen;

}

int main() {
    string s1 = "xtxoxcxtoc";
    string s2 = "toc";
    int result = minimumWindowSubstr(s1, s2);
    cout << result;

    return 0;
}