#include <iostream>
#include <vector>

using namespace std;

int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int size = sizeof(deno) / sizeof(deno[0]);

vector<int> findChange(int value) {
    vector<int> result;
    sort(deno, deno + size);

    for(int i = size - 1; i >= 0; i--) {
        while(deno[i] <= value) {
            value = value - deno[i];
            result.push_back(deno[i]);
        }
    }

    return result;
}

int main() {
    int n = 49;
    vector<int> change = findChange(n);
    for(int i = 0; i < change.size(); i++) {
        cout << change[i] << "\t";
    }
    return 0;
}