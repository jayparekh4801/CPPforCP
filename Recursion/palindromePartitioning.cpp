#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }

    return true;
}

void allPartitions(int ind, vector<string> path, vector<vector<string> >& result, string s) {
    if(ind == s.size()) {
        result.push_back(path);
        return;
    }

    for(int i = ind; i < s.size(); i++) {
        if(isPalindrome(s, ind, i)) {
            path.push_back(s.substr(ind, i - ind + 1));
            allPartitions(i + 1, path, result, s);
            path.pop_back();
        }
    }
}

vector<vector<string> > palindromePartitions(string s) {
    vector<string> path;
    vector<vector<string> > result;
    allPartitions(0, path, result, s);
    return result;
}

int main() {
    string s;
    cin >> s;

    vector<vector<string> > result = palindromePartitions(s);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}