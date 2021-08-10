#include <iostream>

using namespace std;

string subWindow(string s, string t) {
    int l = -1;
    int r = -1;
    string result = "", temp = "";

    for(int i = 0, j = 0; i <= s.length();) {

        if(j == t.length()) {
            r = i - 1;
            temp = s.substr(l, r - l + 1);
            if(temp.length() < result.length() || result.length() == 0) {
                result = temp;
            }
            j = 0;
            l = -1;
            r = -1;
        }

        if(s[i] == t[j]) {
            if(l == -1 && r == -1) {
                l = i;
            }
            i++;
            j++;
        }
        else {
            i++;
        }

    }

    return result; 

}

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    string result = subWindow(s, t);
    cout << result;
    return 0;
}