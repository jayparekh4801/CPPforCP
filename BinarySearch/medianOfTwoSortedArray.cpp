#include <iostream>

using namespace std;

int median(int a[], int b[], int n1, int n2) {
    int l = 0;
    int h = n1 - 1;
    int ellh;

    if((n1 + n2) % 2 == 0) {
        ellh = (n1 + n2) / 2;
    }
    else {
        ellh = ((n1 + n2) / 2) + 1;
    }

    while(l <= h) {
        int mid = (l + h) / 2;
        int l1 = a[mid];
        int l2 = b[ellh - mid - 2];
        int r1 = a[mid + 1];
        int r2 = b[ellh - mid - 1];

        if(l1 <= r2 && l2 <= r1) {
            if((n1 + n2) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2) / 2);
            }
            else {
                return max(l1, l2);
            }
        }

        else if(l1 > r2) {
            h = mid - 1;
        }

        else if(l2 > r1) {
            l = mid + 1;
        }
    } 

}

int main() {
    int n1, n2;
    cin >> n1;
    cin >> n2;

    int a[n1], b[n2];

    for(int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    for(int i = 0 ; i < n2; i++) {
        cin >> b[i];
    }

    int result = median(a, b, n1, n2);
    cout << result;
    return 0;
}