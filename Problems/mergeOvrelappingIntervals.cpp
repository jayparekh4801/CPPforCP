#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > mergeOverlapingIntervals(vector<vector<int> > a, int n) {
    vector<vector<int> > result;
    if(a.size() == 0) {
        return result;
    }

    sort(a.begin(), a.end());

    vector<int> temp = a[0];

    for(vector<int> it : a) {
        if(it[0] <= temp[1]) {
            temp[1] = max(temp[1], it[1]);
        }
        else {
            result.push_back(temp);
            temp = it;
        }
    }
    result.push_back(temp);
    return result;
}

int main() {
    vector<vector<int> > q;
    // {{1, 3}, {2, 6}, {8, 10}, {15, 18}}
    int n = 4;
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        int t;
        cin >> t;
        temp.push_back(t);
        cin >> t;
        temp.push_back(t);
        q.push_back(temp);
    }

    vector<vector<int> > result = mergeOverlapingIntervals(q, n);
    for(int i  = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]\n";
    }

    return 0;
}