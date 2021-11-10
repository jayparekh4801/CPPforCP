// Problem Statement :- Delete Middle Element Of Stack Using Recursion

#include <iostream>
#include <stack>

using namespace std;

void deleteMid(stack<int>& s, int k) {
    if(k == 1) {
        s.pop();
        return;
    }

    int val = s.top();
    s.pop();
    deleteMid(s, k - 1);
    s.push(val);
}

int main() {
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(7);
    int k = (s.size() / 2) + 1;

    deleteMid(s, k);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}