#include <iostream>
#include <map>

using namespace std;


int findMaxIndex(int fre[], int n) {
    int result;
    int crmax = fre[0];

    for(int i = 0; i < n; i++) {
        if(fre[i] > crmax) {
            crmax = fre[i];
            result = i;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int max = 0;
    int op[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > max) {
            max = a[i];
        }
    }

    int fre[max + 1];

    for(int i = 0; i < max + 1; i++) {
        fre[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        fre[a[i]]++;
    }

    for(int i = 0; i < n;) {
        int maxIdx = findMaxIndex(fre, max + 1);
        int times = fre[maxIdx];
        fre[maxIdx] = 0;
        while(times != 0) {
            op[i] = maxIdx;
            times--;
            i++;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << op[i] << " ";
    }
    return 0;
}