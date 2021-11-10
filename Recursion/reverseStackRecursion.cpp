// Problem Statement :- Reverse Stack Using Recursion

#include <iostream>
#include <stack>

using namespace std;

void putInPlace(stack<int>& s, int val) {
    if(s.size() == 0) {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    putInPlace(s, val);
    s.push(temp);
}

void reverseStack(stack<int>& s) {
    if(s.size() == 1) {
        return;
    }

    int val = s.top();
    s.pop();
    reverseStack(s);
    putInPlace(s, val);
}

int main() {
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(7);

    reverseStack(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}