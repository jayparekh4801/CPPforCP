#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string x) {
    if(x[0] == ')' || x[0] == '}' || x[0] == ']') {
            return false;
        }
        stack<char> s;
        s.push('$');
        s.push(x[0]);
        
        for(int i = 1; i < x.length(); i++) {
            if(x[i] == '(' || x[i] == '{' || x[i] == '[') {
                cout << 'o';
                s.push(x[i]);
            }
            else {
                if(x[i] == ')' && s.top() == '(') {
                    s.pop();
                }
                else if(x[i] == '}' && s.top() == '{') {
                    s.pop();
                }
                else if(x[i] == ']' && s.top() == '[') {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        if(s.top() == '$') {
            return true;
        }
    return false;
}

int main() {
    string x;
    cin >> x;
    bool result = isBalanced(x);

    if(result) {
        cout << "Balanced";
    }
    else {
        cout << "Not Balanced";
    }

    return 0;
}