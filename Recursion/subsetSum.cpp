#include <iostream>
#include <vector>

using namespace std;

void subsetSum(int a[], int n, int i, int sum, vector<int>& result) {
    if(i == n) {
        result.push_back(sum);
        return;
    }

    subsetSum(a, n, i + 1, sum, result);
    subsetSum(a, n, i + 1, sum + a[i], result);
}

vector<int> findsubsetSum(int a[], int n) {
    vector<int> result;
    subsetSum(a, n, 0, 0, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result;

    result = findsubsetSum(a, n);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}