#include <iostream>
#include <vector>

using namespace std;

void allPermutations(int a[], vector<int> ds, vector<vector<int> >& result, int fre[], int n) {
    if(ds.size() == n) {
        result.push_back(ds);
    }

    for(int i = 0; i < n; i++) {
        if(fre[i] == 0) {
            fre[i] = 1;
            ds.push_back(a[i]);
            allPermutations(a, ds, result, fre, n);
            ds.pop_back();
            fre[i] = 0;
        }
    }

}

vector<vector<int> > permutaions(int a[], int n) {
    int fre[n];

    for(int i = 0; i < n; i++) {
        fre[i] = 0;
    }

    vector<vector<int> > result;
    vector<int> ds;

    allPermutations(a, ds, result, fre, n);
    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int> > result = permutaions(a, n);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << "\n";
    }


    return 0;
}