#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int occurances(string major, string minor) {
    int minlen = minor.length();
    int majlen = major.length();
    int result = 0;
    transform(major.begin(), major.end(), major.begin(), ::toupper);
    transform(minor.begin(), minor.end(), minor.begin(), ::toupper);

    for(int i = 0; i <= majlen - minlen; i++) {
        string temp = major.substr(i, minlen);
        if(temp == minor) {
            result++;
        }
    }

    return result;
}

int main() {
    string major;
    string minor;

    // cin >> major;
    // cin >> minor;
    major = "jaydjaydjay";
    minor = "jay";

    int result = occurances(major, minor);
    cout << result;
    return 0;
}