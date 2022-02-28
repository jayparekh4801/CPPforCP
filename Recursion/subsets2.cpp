#include <iostream>
#include <vector>

using namespace std;

void getAllSubsets(vector<int> a, vector<int> ds, vector<vector<int> >& result, int ind) {
    result.push_back(ds);
    int n = a.size(); 
    for(int i = ind; i < n; i++) {
        if(i != ind && a[i - 1] == a[i]) {
            continue;
        }
        ds.push_back(a[i]);
        getAllSubsets(a, ds, result, ind + 1);
        ds.pop_back();
    }
}

vector<vector<int> > allSubsets(vector<int> a) {
    sort(a.begin(), a.end());
    vector<int> ds;
    vector<vector<int> > result;
    getAllSubsets(a, ds, result, 0);
    return result;

}

int main() {
    vector<int> a;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    vector<vector<int> > result = allSubsets(a);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}