#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > mergeOverlapingIntervals(vector<vector<int> > a, int n) {
    sort(a.begin(), a.end());
    vector<vector<int> > result;
    vector<int> temp;
    temp.push_back(a[0][0]);
    temp.push_back(a[0][1]);
    result.push_back(temp);
    int index = 0;
    for(int i = 1; i < a.size(); i++) {
        if(a[i][0] <= result[index][1]) {
            result[index][1] = max(result[index][1], a[i][1]);
        }
        else {
            vector<int> temp1;
            temp1.push_back(a[i][0]);
            temp1.push_back(a[i][1]);
            result.push_back(temp1);
        }
    }

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