#include <iostream>

using namespace std;

int findIndex(string para, string needle, int pl, int nl) {
    int result = -1;
    for(int i = 0; i < pl - nl + 1; i++) {
        string temp = para.substr(i, nl);
        if(temp == needle) {
            result = i;
            break;
        }
    }
    return result;
}

int main() {
    string para, needle;

    getline(cin, para);
    getline(cin, needle);

    int result = findIndex(para, needle, para.length(), needle.length());
    cout << result;

    return 0;
}

