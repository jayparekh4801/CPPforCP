#include<iostream>
#include<vector>

using namespace std;

void findAllSubsets(string s, string op, vector<string>& result) {
    if(s.length() == 0) {
        result.push_back(op);
        return;
    }
    if(s[0] == ' ') {
        string op1 = op;
        string op2 = op;
        op2.push_back(s[0]);
        s.erase(s.begin() + 0);
        findAllSubsets(s, op1, result);
        findAllSubsets(s, op2, result);
    }
    else {
        string op1 = op;
        op1.push_back(s[0]);
        s.erase(s.begin() + 0);
        findAllSubsets(s, op1, result);
    }
}

int main() {
    string s = "A B C";
    string op = "";
    vector<string> result;
    findAllSubsets(s, op, result);
    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
    return 0;
}