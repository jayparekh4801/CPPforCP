#include <iostream>
#include <vector>

using namespace std;

int fact(int n) {
    int result = 1;

    for(int i = n; i > 0; i--) {
        result *= i;
    }

    return result;
}

vector<int> kthPermute(vector<int> a, int k) {
    vector<int> result;
    k--;
    int ts = fact(a.size());
    while(a.size() != 0) {
        ts /= a.size();
        int place = k / ts;
        result.push_back(a[place]);
        a.erase(a.begin() + place);
        k = k % ts;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int k;
    vector<int> a;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    cin >> k;

    vector<int> result = kthPermute(a, k);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}