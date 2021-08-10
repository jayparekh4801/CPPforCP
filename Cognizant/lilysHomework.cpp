#include <iostream>

using namespace std;

int findSwaps(int arr[], int n) {

    pair<int , int> arrpos[n];
    int result = 0;

    for(int i = 0; i < n; i++) {
        arrpos[i].first = arr[i];
        arrpos[i].second = i;
    }

    sort(arrpos, arrpos + n);

    bool vis[n];

    for(int i = 0; i < n; i++) {
        vis[i] = false;
    }

    for(int i = 0; i <n; i++) {

        if(vis[i] || arrpos[i].second == i) {
            continue;
        }

        else {
            int cycle_size = 0;
            int j = i;

            while(!vis[j]) {
                vis[j] = true;
                j = arrpos[j].second;
                cycle_size++;
            }

            if(cycle_size > 0) {
                result = result + (cycle_size - 1);
            }
        }
    } 

    return result;

}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findSwaps(arr, n);
    cout << result;
    return 0;
}