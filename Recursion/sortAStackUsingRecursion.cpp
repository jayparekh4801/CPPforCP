// Problem Statement :- Sort A Stack Using Recursion

#include <iostream>
#include <stack>

using namespace std;

void putInStack(stack<int>& s, int val) {
    if(s.size() == 0 || s.top() <= val) {
        s.push(val);
    }

    if(s.top() > val) {
        int temp = s.top();
        s.pop();
        putInStack(s, val);
        s.push(temp);
    }
    return;
}

void sortStack(stack<int>& s) {
    if(s.size() == 1) {
        return;
    }
    int val = s.top();
    s.pop();
    sortStack(s);
    putInStack(s, val);
}

int main() {
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(7);
    sortStack(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}