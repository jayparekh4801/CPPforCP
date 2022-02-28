#include <iostream>
#include <vector>

using namespace std;

void allCombinationSum2(vector<int>& a, int ind, int target, vector<int> ds, vector<vector<int> >& result) {
    if(target == 0) {
        result.push_back(ds);
    }

    for(int i = ind; i < a.size(); i++) {
        if(i != ind && a[i - 1] == a[i]) {
            continue;
        }
        if(a[i] > target) {
            break;
        }

        ds.push_back(a[i]);
        allCombinationSum2(a, i + 1, target - a[i], ds, result);
        ds.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int> a, int target) {
    sort(a.begin(), a.end());
    vector<int> ds;
    vector<vector<int> > result;
    allCombinationSum2(a, 0, target, ds, result);
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
    int target;
    cin >> target;
    vector<vector<int> > result = combinationSum2(a, target);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}