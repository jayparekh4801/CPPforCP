#include <iostream>
#include <vector>

using namespace std;

void allPara(int open, int close, string op, vector<string>& result) {
    if(open == 0 && close == 0) {
        result.push_back(op);
        return;
    }

    if(open == close) {
        op += "(";
        open--;
        allPara(open, close, op, result);
    }

    else if(open == 0 && close != 0) {
        op += ")";
        close--;
        allPara(open, close, op, result);
    }
    
    else {
        string op1 = op + "(";
        string op2 = op + ")";
        allPara(open - 1, close, op1, result);
        allPara(open, close - 1, op2, result);
    }

}

int main() {
    int n;
    cin >> n;
    vector<string> result;
    string op = "";
    allPara(n, n, op, result);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}