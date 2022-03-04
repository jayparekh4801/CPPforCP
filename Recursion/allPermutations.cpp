#include <iostream>
#include <vector>

using namespace std;

void allPermutations(int ind, vector<vector<int> >& result, vector<int> a, int n) {
    if(ind == n - 1) {
        result.push_back(a);
        return;
    }

    for(int i = ind; i < n; i++) {
        swap(a[ind], a[i]);
        allPermutations(ind + 1, result, a, n);
        swap(a[ind], a[i]);
    }
}

vector<vector<int> > permutaions(vector<int> a, int n) {
    vector<vector<int> > result;
    allPermutations(0, result, a, n);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    vector<vector<int> > result = permutaions(a, n);
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        count++;
        cout << "\n";
    }


    return 0;
}