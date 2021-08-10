#include <iostream>

using namespace std;

int savedPrisoner(int p, int s, int in) {
    int result = in - 1;

    for(int i = 0; i < s; i++) {
        if(result == p) {
            result = 1;
        }
        else {
            result++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int p, s, in, result;
        cin >> p;
        cin >> s;
        cin >> in;
        result = savedPrisoner(p, s, in);
        cout << result << endl;
    }

    return 0;
}