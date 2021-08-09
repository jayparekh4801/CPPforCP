#include <iostream>

using namespace std;

void compareString(string p, string q) {
    int pp = 0;
    int qp = 0;
    
    if(p == q) {
        cout << "NA";
        return;
    }

    while(qp < q.length()) {
        if(q[qp] == p[pp]) {
            qp++;
            pp++;
        }

        else {
            cout << q[qp];
            qp++;
        }
    }
}

int main() {
    string p = "abc";
    string q = "abc";

    compareString(p, q);
    return 0;
}