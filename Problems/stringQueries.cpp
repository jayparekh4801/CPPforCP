#include <iostream>
#include <vector>
#include <set>

using namespace std;
int calculateXorValue(int N, string str, vector<vector<int> > operations) {
    int queries = operations.size();
    int result = INT_MIN;
    for(int i = 0; i < queries; i++) {
        if(operations[i][0] == 1) {
            str[operations[i][1] - 1] = operations[i][2] + 97;
        }
        else if(operations[i][0] == 2) {
            cout << str;
            int dis = 0;
            set<int> s;
            for(int j = operations[i][1] - 1; j < N && j <= operations[i][2] - 1; j++) {
                s.insert(str[j]);
            }
            dis = s.size();
            if(result == INT_MIN) {
                result = dis;
            }
            else {
                result = result ^ dis;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int> > operations;
    int o;
    cin >> o;
    for(int i = 0; i < o; i++) {
        vector<int> temp;
        int qt, f, s;
        cin >> qt;
        cin >> f;
        cin >> s;
        temp.push_back(qt);
        temp.push_back(f);
        temp.push_back(s);
        operations.push_back(temp);
    }

    int result = calculateXorValue(n, s, operations);
    cout << result;

    return 0;
}