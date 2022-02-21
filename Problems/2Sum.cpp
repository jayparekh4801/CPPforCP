#include <iostream>
#include <vector>

using namespace std;

vector<int> sum2(int a[], int n, int target) {
    vector<int> result;
        map<int, int> m;
        
        for(int i = 0; i < n; i++) {
            if(m.find(a[i]) != m.end()) {
                result.push_back(m[a[i]]);
                result.push_back(i);
                return result;
            }
            else {
                m.insert(make_pair(target - a[i], i));
            }
        }
        return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int target;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> target;
    vector<int> result = sum2(a, n, target);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
    }

    return 0;
}