#include <iostream>

using namespace std;

string excelColumn(int n) {
    cout << n % 26;
    return "";
}

int main() {
    int n;
    cin >> n;

    string result = excelColumn(n);
    cout << result;
    return 0;
}