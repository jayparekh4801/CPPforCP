#include <iostream>
#include <vector>

using namespace std;

void subsets(vector<int> a, int target, vector<int> ds, vector<vector<int> >& result, int n) {
    if(n == 0) {
        if(target == 0) {
            result.push_back(ds);
        }
        return;
    }

    if(a[n - 1] <= target) {
        ds.push_back(a[n - 1]);
        subsets(a, target - a[n - 1], ds, result, n);
        ds.pop_back();
    }
    subsets(a, target, ds, result, n - 1);
    
}

vector<vector<int> > combinatinonSum(vector<int> a, int target) {
    vector<int> ds;
    vector<vector<int> > result;
    int n = a.size();
    subsets(a, target, ds, result, n);
    return result;

}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    int target;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    cin >> target;

    vector<vector<int> > result = combinatinonSum(a, target);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}