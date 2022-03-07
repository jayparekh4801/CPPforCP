#include <iostream>
#include <vector>

using namespace std;

bool isWord(string s, vector<string> dictionary) {

    for(int i = 0; i < dictionary.size(); i++) {
        if(s == dictionary[i]) {
            return true;
        }
    }


    return false;
}

void allBreaks(int ind, vector<string> path, vector<string>& result, vector<string> dictionary, string s) {
    if(ind == s.size()) {
        string res = "";
        for(int i = 0; i < path.size(); i++) {
            res += path[i];
            res += " ";
        }
        result.push_back(res);
        return;
    }

    for(int i = ind; i < s.size(); i++) {
        if(isWord(s.substr(ind, i - ind + 1), dictionary)) {
            path.push_back(s.substr(ind, i - ind + 1));
            allBreaks(i + 1, path, result, dictionary, s);
            path.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> dictionary;
    vector<string> path;
    string s;
    vector<string> result;


    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        dictionary.push_back(temp);
    }

    cin >> s;

    allBreaks(0, path, result, dictionary, s);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}