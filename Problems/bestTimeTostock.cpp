#include <iostream>

using namespace std;

int stock(int prices[], int n) {
    int mi = INT_MAX;
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(prices[i] <= mi) {
            mi = prices[i];
            continue;
        }
        
        result = max(result, prices[i] - mi);
        
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    int result = stock(a, n);

    cout << result;
    return 0;
}