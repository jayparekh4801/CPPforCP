#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maximumOfAllSubarray(int a[], int n, int k) {
    vector<int> result;
    int l = 0; 
    int r = 0;
    vector<int> maxEl;
    maxEl.push_back(INT_MIN);

    while(r < n) {
        if(maxEl.front() < a[r]) {
            maxEl.clear();
        }
        maxEl.push_back(a[r]);
        if(r - l + 1 < k) {
            r++;
            continue;
        }

        if(r - l + 1 == k) {
            result.push_back(maxEl.front());
            if(a[l] == maxEl.front()) {
                maxEl.erase(maxEl.begin());
            }
            r++;
            l++;
        }
    }
    return result;
}

int main() {
    int a[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = 9;
    int k = 3;
    vector<int> result = maximumOfAllSubarray(a, n, k);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\t";
    }
    return 0;
}